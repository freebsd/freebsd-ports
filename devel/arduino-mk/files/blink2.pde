/* @(#) $Id: blink2.pde 18 2012-02-05 20:38:31Z leres $ (XSE) */

/*
 * This is a example sketch that blinks the LED like a heartbeat
 */

/* SCK is usually connected to the LED */
#define PIN_LED_OUT SCK

void
setup()
{
	pinMode(PIN_LED_OUT, OUTPUT);
}

void
loop()
{
	digitalWrite(PIN_LED_OUT, HIGH);
	delay(25);

	digitalWrite(PIN_LED_OUT, LOW);
	delay(50);

	digitalWrite(PIN_LED_OUT, HIGH);
	delay(25);

	digitalWrite(PIN_LED_OUT, LOW);
	delay(900);
}
