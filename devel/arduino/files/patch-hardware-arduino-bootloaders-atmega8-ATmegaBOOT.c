--- hardware/arduino/bootloaders/atmega8/ATmegaBOOT.c.orig	2011-03-21 15:17:03.000000000 +0800
+++ hardware/arduino/bootloaders/atmega8/ATmegaBOOT.c	2011-03-21 15:17:23.000000000 +0800
@@ -36,7 +36,7 @@
 #include <avr/pgmspace.h>
 #include <avr/eeprom.h>
 #include <avr/interrupt.h>
-#include <avr/delay.h>
+#include <util/delay.h>
 
 //#define F_CPU			16000000
 
