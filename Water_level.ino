// include libraries
#include <Wire.h>
#include <LCD.h>
#include <LiquidCrystal_I2C.h>
/********************************/
int sensorPin = A1;  // select the input pin (must be analog) for the water level sensor module
int ledPin = 8;      // select the pin for the LED
int sensorValue = 0; // variable to store the value coming from the sensor
LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);// initialise the LCD
/********************************/
void setup() {
  Serial.begin(9600); // initialize serial communications at 9600 bps
  pinMode(ledPin, OUTPUT);  // declare the ledPin as an OUTPUT
  lcd.begin (16, 2);    // define the LCD as 16 column by 2 rows
  lcd.setBacklightPin(3, POSITIVE);
  lcd.setBacklight(HIGH); // switch on the backlight
}

void loop() {

  sensorValue = analogRead(sensorPin); // read the value from the sensor

  if (sensorValue <= 0) {
    lcd.setCursor(0, 0);
    lcd.print("Water lvl: 0mm");
    Serial.println("Water level: 0mm - Empty!");
  }
  else if (sensorValue > 0 && sensorValue <= 223) {
    lcd.setCursor(0, 0);
    lcd.print("Water lvl:0-5mm");
    lcd.setCursor(0, 1);
    lcd.print("Alarm! Alarm!");
    Serial.println("Water lvl:0-5mm");
    digitalWrite(ledPin, HIGH);  // turn the ledPin on
  }
  else if (sensorValue > 223 && sensorValue <= 251) {
    lcd.setCursor(0, 0);
    lcd.print("Water lvl:5-10mm");
    Serial.println("Water lvl: 5-10mm");
  }
  else if (sensorValue > 251 && sensorValue <= 277) {
    lcd.setCursor(0, 0);
    lcd.print("Water lvl:10-15mm");
    Serial.println("Water lvl: 10-15mm");
  }
  else if (sensorValue > 277 && sensorValue <= 294) {
    lcd.setCursor(0, 0);
    lcd.print("Water lvl:15-20mm");
    Serial.println("Water lvl: 15-20mm");
  }
  else if (sensorValue > 294 && sensorValue <= 311) {
    lcd.setCursor(0, 0);
    lcd.print("Water lvl:20-25mm");
    Serial.println("Water lvl: 20-25mm");
  }
  else if (sensorValue > 311 && sensorValue <= 314) {
    lcd.setCursor(0, 0);
    lcd.print("Water lvl:25-30mm");
    Serial.println("Water lvl: 25-30mm");
  }
  else if (sensorValue > 314 && sensorValue <= 323) {
    lcd.setCursor(0, 0);
    lcd.print("Water lvl:30-35mm");
    Serial.println("Water lvl: 30-35mm");
  }
  else if (sensorValue > 323) {
    lcd.setCursor(0, 0);
    lcd.print("Water lvl:35-40mm");
    Serial.println("Water lvl: 35-40mm");
  }
  delay(1000); // delay 1 second
  lcd.clear(); // clear LCD screen
  digitalWrite(ledPin, LOW);
  // turn the ledPin off - reset
  // the system when sensor out of the water and dry

}
