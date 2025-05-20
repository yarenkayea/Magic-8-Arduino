#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);  
const int buttonPin = 2;     
     

bool buttonPressed = false;

String answers[] = {
  "Evet", "Hayir", "Belki", "Kesinlikle", "Asla",
  "Daha sonra", "Sor tekrar", "Emin degilim",
  "Su an olmaz", "Neden olmasin?", "Zaman gosterir",
  "Muhtemelen", "Sanmiyorum", "Supheli",
  "Cok olasi", "Garanti!"
};

const int totalAnswers = sizeof(answers) / sizeof(answers[0]);

void setup() {
  lcd.begin();
  lcd.backlight();

  pinMode(buttonPin, INPUT_PULLUP); 
  

  Serial.begin(9600);
  randomSeed(analogRead(A0));  

  lcd.setCursor(0, 0);
  lcd.print("Butona basin...");
}

void loop() {
  if (digitalRead(buttonPin) == LOW && !buttonPressed) {
    buttonPressed = true;

    int index = random(0, totalAnswers); 

    
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Cevap:");
    lcd.setCursor(0, 1);
    lcd.print(answers[index]);

    Serial.println("Cevap: " + answers[index]);

    delay(1000);
  }

  if (digitalRead(buttonPin) == HIGH) {
    buttonPressed = false;
  }
}
