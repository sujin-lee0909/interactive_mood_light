#include <Wire.h>
#include "RTClib.h"
#include <LiquidCrystal_I2C.h>

RTC_DS1307 RTC;
LiquidCrystal_I2C lcd(0x27, 16, 2);

//lcd
byte cloud1[8] = {
  0b01110,
  0b10001,
  0b00000,
  0b00000,
  0b00000,
  0b00000,
  0b11001,
  0b01110
};

byte cloud2[8] ={
  0b00000,
  0b00001,
  0b00110,
  0b11000,
  0b10000,
  0b11000,
  0b01100,
  0b00111
};

byte cloud3[8] ={
  0b00000,
  0b10000,
  0b01100,
  0b00011,
  0b00001,
  0b00011,
  0b01100,
  0b11000
};

byte rainy1[8] ={
  0b00010,
  0b00010,
  0b00010,
  0b01010,
  0b01000,
  0b01000,
  0b00001,
  0b00001
};

byte rainy2[8] ={
  0b00000,
  0b01000,
  0b01000,
  0b01010,
  0b00010,
  0b00010,
  0b00000,
  0b00000
};

byte rainy3[8]={
  0b10000,
  0b10000,
  0b10001,
  0b00001,
  0b00001,
  0b00100,
  0b00100,
  0b00000,
};

byte snowing1[8] ={
  0b00011,
  0b00011,
  0b00010,
  0b11000,
  0b11000,
  0b00000,
  0b00011,
  0b00011
};

byte snowing2[8] ={
  0b00000,
  0b01100,
  0b01100,
  0b00000,
  0b00011,
  0b00011,
  0b00000,
  0b00000
};

byte snowing3[8]={
  0b11000,
  0b11000,
  0b00000,
  0b00011,
  0b00011,
  0b0000,
  0b01100,
  0b01100,
};

byte sunny1[8] = {
  0b00000,
  0b00000,
  0b00000,
  0b00000,
  0b00011,
  0b01110,
  0b11000,
  0b10000
};

byte sunny2[8] = {
  0b01000,
  0b11000,
  0b10000,
  0b00000,
  0b11000,
  0b01110,
  0b00011,
  0b00001
};

byte sunny3[8] = {
  0b10000,
  0b11000,
  0b01110,
  0b00011,
  0b00000,
  0b00001,
  0b00011,
  0b00010
};

byte sunny4[8] = {
  0b00001,
  0b00011,
  0b01110,
  0b11000,
  0b00000,
  0b00000,
  0b00000,
  0b00000,
};

byte sunny5[8] = {
  0b11000,
  0b01100,
  0b00000,
  0b00000,
  0b00000,
  0b00000,
  0b00000,
  0b00000,
};

byte sunny6[8] = {
  0b00000,
  0b00000,
  0b00000,
  0b00000,
  0b00000,
  0b00000,
  0b00110,
  0b00011,
};

byte windy1[8]={
  0b00000,
  0b00000,
  0b00000,
  0b11111,
  0b00000,
  0b00000,
  0b11111
};

byte windy2[8]={
  0b00000,
  0b11000,
  0b01110,
  0b11100,
  0b00000,
  0b00000,
  0b11111
};

byte windy3[8]={
  0b00000,
  0b11111,
  0b00000,
  0b00000,
  0b11111,
  0b00000,
  0b00000
};

byte windy4[8]={
  0b00000,
  0b11111,
  0b00000,
  0b00000,
  0b11110,
  0b00110,
  0b01100
};

byte windy5[8]={
  0b00000,
  0b00000,
  0b00000,
  0b01110,
  0b00011,
  0b00011,
  0b11110
};

byte windy6[8]={
  0b00000,
  0b11100,
  0b00111,
  0b00110,
  0b11100,
  0b00000,
  0b00000
};

//RTC
char daysOfTheWeek[7][12] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};

//button
int btn1 =2;
int btn2 =4;
int btn3 =7;
int b1v, b2v, b3v; //button value

//rgb led
int r = 9;
int g = 10;
int b = 11;

int r2=3;
int g2=5;
int b2=6;

int rv=0;
int gv=0;
int bv=0;
  
void setup() {
  // put your setup code here, to run once:

  //button
  pinMode(btn1, INPUT);
  pinMode(btn2, INPUT);
  pinMode(btn3, INPUT);

  //RGB led
  pinMode(r,OUTPUT);
  pinMode(g,OUTPUT);
  pinMode(b,OUTPUT);

  pinMode(r2,OUTPUT);
  pinMode(g2,OUTPUT);
  pinMode(b2,OUTPUT);
  
  //RTC Module
  Wire.begin();
  RTC.begin();

  //lcd
  lcd.begin();

  Serial.begin(9600);

}

int num=0;
int weather=0;

void loop() {
  //Serial.println("loop");
  // put your main code here, to run repeatedly:
  b1v = digitalRead(btn1);
  b2v = digitalRead(btn2);
  b3v = digitalRead(btn3);

  if(b1v == HIGH && b2v == HIGH && b3v == HIGH){
    if(num!=0){
      lcd.clear();
      num = 0;
      weather = 0;
    }
    time();
  }

  else if(b1v == LOW && b2v == LOW && b3v == HIGH){
    if(num!=1){
      num=1;
      lcd.clear();
      weather=random(1,5);
    }
  }
  else if (b1v==LOW && b2v==HIGH && b3v == LOW){
    if(num!=2){
      num=2;
      lcd.clear();
      weather=random(1,5);
    }
  }
  else if (b1v==HIGH && b2v == LOW && b3v == LOW){
    if(num!=3){
      num = 3;
      lcd.clear();
      weather=random(1,5);
    }
  }

  if(b1v == HIGH && b2v == HIGH && b3v == HIGH){
    setColor(0,0,0);
  }
  change(weather);
}

void change(int weather){
  //weather = sunny, rainy, cloud, windy, snowing
  if(weather == 1){ //sunny
    Serial.println("sunny");
    sunny();
    if(rv==0&&gv==0&&bv==0) colorChange(50, 0, 0);
  }
  else if (weather ==2){ //rainy
    Serial.println("rainy");
    rainy();
    if(rv==0&&gv==0&&bv==0) colorChange(50,100,0);
  }
  else if (weather ==3){ //cloud
    Serial.println("cloud");
    cloudy();
    if(rv==0&&gv==0&&bv==0) colorChange(10,200,100);
  }
  else if(weather ==4){ //windy
    Serial.println("windy");
    windy();
    if(rv==0&&gv==0&&bv==0) colorChange(10,200,200);
  }
  else if(weather ==5){ //snowing
    Serial.println("snowing");
    snowing();
    if(rv==0&&gv==0&&bv==0) colorChange(200,200,200);
  }
  else{
    if(rv>0 || gv>0 || bv>0) colorChange(0,0,0);
  }
}

void colorChange(int red, int green, int blue){
  //켜지기
  if(red>0||green>0||blue>0){
    Serial.println("colorChange started");
    for(; rv<red || gv<green || bv<blue; ){
      if(rv<red) rv+=10;
      if(gv<green) gv+=10;
      if(bv<blue) bv+=10;
      setColor(rv,gv,bv);
      delay(30);
    }
    rv=red;
    gv=green;
    bv=blue;
    Serial.println("colorChange ended");
  }
  else if(red==0&&green==0&&blue==0){
    for(;rv>0||gv>0||bv>0;){
      if(rv>0) rv-=10;
      if(gv>0) gv-=10;
      if(bv>0) bv-=10;
      setColor(rv,gv,bv);
      delay(30);
    }
    rv=0;
    gv=0;
    bv=0;
  }
}

void setColor(int red, int green, int blue){
  analogWrite(r,red);
  analogWrite(g,green);
  analogWrite(b,blue);
  analogWrite(r2,red);
  analogWrite(g2,green);
  analogWrite(b2,blue);
}

void time(){
  DateTime now = RTC.now();

  Serial.print(now.year(), DEC);  // 년
  Serial.print('/');
  Serial.print(now.month(), DEC);  // 월
  Serial.print('/');
  Serial.print(now.day(), DEC);   // 일
  Serial.print(' ');
  Serial.print(now.hour(), DEC);    // 시간
  Serial.print(':');
  Serial.print(now.minute(), DEC);   // 분
  Serial.print(':');
  Serial.print(now.second(), DEC);   // 초
  Serial.print(' ');

  Serial.print(daysOfTheWeek[now.dayOfTheWeek()]);   // 요일

  Serial.println();

  delay(1000);

  if(now.hour()<10){
    lcd.setCursor(3,0);
    lcd.print(0);
    lcd.setCursor(4,0);
    lcd.print(now.hour());
  } else{
    lcd.setCursor(3,0);
    lcd.print(now.hour());
  }

  lcd.setCursor(5,0);
  lcd.print("Hr ");
  
  if(now.minute()<10){
    lcd.setCursor(8,0);
    lcd.print(0);
    lcd.setCursor(9,0);
    lcd.print(now.minute());
  } else{
  lcd.setCursor(8,0);
  lcd.print(now.minute());
  }

  lcd.setCursor(10,0);
  lcd.print("Min");

  lcd.setCursor(3,1);
  lcd.print("Happy Day");
/*
  if(now.second()<10){
    lcd.setCursor(10,0);
    lcd.print(0);
    lcd.setCursor(11,0);
    lcd.print(now.second());
  } else{
  lcd.setCursor(10,0);
  lcd.print(now.second());
  }
*/
}

void rainy(){
  lcd.createChar(1,cloud2);
  lcd.createChar(2,cloud1);
  lcd.createChar(3,cloud3);
  lcd.createChar(4,rainy1);
  lcd.createChar(5,rainy2);
  lcd.createChar(6,rainy3);
  
  lcd.setCursor(8,0);
  lcd.print("rainy");
  lcd.setCursor(9,1);
  lcd.print("day");
  
  lcd.setCursor(3,0);
  lcd.write(1);
  lcd.setCursor(4,0);
  lcd.write(2);
  lcd.setCursor(5,0);
  lcd.write(3);

  lcd.setCursor(3,1);
  lcd.write(4);
  lcd.setCursor(4,1);
  lcd.write(5);
  lcd.setCursor(5,1);
  lcd.write(6);

  delay(500);

  lcd.setCursor(3,1);
  lcd.write(6);
  lcd.setCursor(4,1);
  lcd.write(4);
  lcd.setCursor(5,1);
  lcd.write(5);

  delay(500);
}

void windy(){
  lcd.createChar(1,windy1);
  lcd.createChar(2,windy2);
  lcd.createChar(3,windy3);
  lcd.createChar(4,windy4);
  lcd.createChar(5,windy5);
  lcd.createChar(6,windy6);
    
  lcd.setCursor(9,0);
  lcd.print("windy");
  lcd.setCursor(10,1);
  lcd.print("day");

  lcd.setCursor(4,0);
  lcd.write(1);
  lcd.setCursor(5,0);
  lcd.write(2);

  delay(200);
  lcd.setCursor(4,1);
  lcd.write(3);
  lcd.setCursor(5,1);
  lcd.write(4);

  delay(200);
  lcd.setCursor(6,0);
  lcd.write(5);
  lcd.setCursor(6,1);
  lcd.write(6);

  delay(200);
}

void sunny(){
  lcd.createChar(1,sunny1);
  lcd.createChar(2,sunny2);
  lcd.createChar(3,sunny3);
  lcd.createChar(4,sunny4);
  lcd.createChar(5,sunny5);
  lcd.createChar(6,sunny6);

  lcd.setCursor(2,0);
  lcd.write(6);
  lcd.setCursor(3,0);
  lcd.write(1);
  lcd.setCursor(4,0);
  lcd.write(2);
  lcd.setCursor(3,1);
  lcd.write(3);
  lcd.setCursor(4,1);
  lcd.write(4);
  lcd.setCursor(5,1);
  lcd.write(5);
  
  lcd.setCursor(8,0);
  lcd.print("sunny");
  lcd.setCursor(9,1);
  lcd.print("day");
}

void cloudy(){
  lcd.createChar(1,cloud2);
  lcd.createChar(2,cloud1);
  lcd.createChar(3,cloud3);
  
  lcd.setCursor(2,0);
  lcd.write(1);
  lcd.setCursor(3,0);
  lcd.write(2);
  lcd.setCursor(4,0);
  lcd.write(3);

  lcd.setCursor(5,1);
  lcd.write(1);
  lcd.setCursor(6,1);
  lcd.write(2);
  lcd.setCursor(7,1);
  lcd.write(3);
  lcd.setCursor(8,0);
  lcd.print("cloudy");
  lcd.setCursor(9,1);
  lcd.print("day");
}

void snowing(){
  lcd.createChar(1,cloud2);
  lcd.createChar(2,cloud1);
  lcd.createChar(3,cloud3);
  lcd.createChar(4,snowing1);
  lcd.createChar(5,snowing2);
  lcd.createChar(6,snowing3);
  
  lcd.setCursor(8,0);
  lcd.print("snowing");
  lcd.setCursor(9,1);
  lcd.print("day");
  
  lcd.setCursor(3,0);
  lcd.write(1);
  lcd.setCursor(4,0);
  lcd.write(2);
  lcd.setCursor(5,0);
  lcd.write(3);

  lcd.setCursor(3,1);
  lcd.write(4);
  lcd.setCursor(4,1);
  lcd.write(5);
  lcd.setCursor(5,1);
  lcd.write(6);

  delay(500);

  lcd.setCursor(3,1);
  lcd.write(6);
  lcd.setCursor(4,1);
  lcd.write(4);
  lcd.setCursor(5,1);
  lcd.write(5);

  delay(500);
}
