--- src/driver.c.orig	2007-01-30 20:58:57 UTC
+++ src/driver.c
@@ -7,8 +7,7 @@
 
 /* available drivers */
 extern Driver  jack_driver;
-extern Driver  alsa_driver;
-static Driver* drivers[] = { &jack_driver, &alsa_driver, NULL };
+static Driver* drivers[] = { &jack_driver, NULL };
 
 /* number of drivers available (we set this var in driver_init ( ) */
 static int ndrivers = 0;
