#include<LiquidCrystal_I2C.h>
#include<string.h>

int pinoUmidade = A0;
int pinoLuminosidade = A1;
long int umidadeOutput;
long int luminosidadeOutput;
long int umidadeValor;
long int luminosidadeValor;

LiquidCrystal_I2C lcd(0x27,20,4);

void setup() {
  Serial.begin(9600);
  lcd.init();
  lcd.backlight();
}

void loop() {
  umidadeOutput = analogRead(pinoUmidade);
  luminosidadeOutput = analogRead(pinoLuminosidade);
  
  umidadeValor = map(umidadeOutput, 0, 1023, 100, 0);
  luminosidadeValor = map(luminosidadeOutput, 0, 1023, 100, 0);
  
  Serial.println(umidadeValor);
  Serial.println(luminosidadeValor);
  
  if (umidadeValor < 15) {
    digitalWrite(11, HIGH);
  }
  else {
    digitalWrite(11, LOW);
  }
  
  lcd.clear();
  lcd.print("Umidade: ");
  lcd.print(umidadeValor);
  lcd.print("%");
  lcd.setCursor(0,1);
  lcd.print("Luminosidade: ");
  lcd.print(luminosidadeValor);
  delay(1000);
}
