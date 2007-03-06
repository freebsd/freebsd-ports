--- src/driver.c.orig	Tue Mar  6 13:09:22 2007
+++ src/driver.c	Tue Mar  6 13:09:35 2007
@@ -7,8 +7,7 @@
 
 /* available drivers */
 extern Driver  jack_driver;
-extern Driver  alsa_driver;
-static Driver* drivers[] = { &jack_driver, &alsa_driver, NULL };
+static Driver* drivers[] = { &jack_driver, NULL };
 
 /* number of drivers available (we set this var in driver_init ( ) */
 static int ndrivers = 0;
