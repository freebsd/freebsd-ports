--- src/VBox/Devices/USB/freebsd/USBProxyDevice-freebsd.cpp.orig	2020-07-09 16:55:58 UTC
+++ src/VBox/Devices/USB/freebsd/USBProxyDevice-freebsd.cpp
@@ -57,7 +57,7 @@
 #include "../USBProxyDevice.h"
 
 /** Maximum endpoints supported. */
-#define USBFBSD_MAXENDPOINTS 127
+#define USBFBSD_MAXENDPOINTS 126
 #define USBFBSD_MAXFRAMES 56
 
 /** This really needs to be defined in vusb.h! */
