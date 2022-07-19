- disable wiringPi.h to unbreak on arm until upstream fixes this for good, see https://github.com/sasagawa888/eisl/issues/180

--- extension.c.orig	2022-07-19 08:14:48 UTC
+++ extension.c
@@ -1,7 +1,7 @@
 #include <stdio.h>
 #include <stdlib.h>
 #include <math.h>
-#ifdef __arm__
+#if 0 && defined(__arm__)
 #include <wiringPi.h>
 #include <wiringPiSPI.h>
 #endif
@@ -47,7 +47,7 @@ initexsubr (void)
   defsubr ("EISL-TEST", f_eisl_test);
 
 
-#ifdef __arm__
+#if 0 && defined(__arm__)
   defsubr ("WIRINGPI-SETUP-GPIO", f_wiringpi_setup_gpio);
   defsubr ("WIRINGPI-SPI-SETUP-CH-SPEED", f_wiringpi_spi_setup_ch_speed);
   defsubr ("PWM-SET-MODE", f_pwm_set_mode);
@@ -454,7 +454,7 @@ f_instance (int arglist)
 }
 
 // ----------for Raspberry PI
-#ifdef __arm__
+#if 0 && defined(__arm__)
 int
 f_wiringpi_setup_gpio (int arglist __unused)
 {
