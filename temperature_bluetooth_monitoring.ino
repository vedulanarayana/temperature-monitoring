#include "DHT.h"

#define DHTPIN 2 // pin for connecting dht11/dht22 sensor

#define DHTTYPE DHT11 // DHT 11 : type of sensor you are using

DHT dht(DHTPIN, DHTTYPE);

void setup()

{ Serial.begin(9600);

  Serial.println("DHT11 Moniter System");

  dht.begin();

}

void loop()

{ delay(2000);// Wait a few seconds for sensor to measure

  float h = dht.readHumidity();

  // Read temperature as Celsius

  float t = dht.readTemperature();

  // Read temperature as Fahrenheit

  float f = dht.readTemperature(true);

  // Check if any reads failed and exit early (to try again).

  if (isnan(h) || isnan(t) || isnan(f))

  { Serial.println("Failed to read from DHT sensor!");

    return;

  }

  float hi = dht.computeHeatIndex(f, h); //compute the heat index, must give temp in fahrenheit

  Serial.print("Humidity: ");

  Serial.print(h);

  Serial.print(" %\n\n");

  Serial.print("Temperature: ");

  Serial.print(t);

  Serial.print(" *C \n");

  Serial.print(f);

  Serial.print(" *F\n");

  Serial.print("Heat index: ");

  Serial.print(hi);

  Serial.println(" *F");

}
