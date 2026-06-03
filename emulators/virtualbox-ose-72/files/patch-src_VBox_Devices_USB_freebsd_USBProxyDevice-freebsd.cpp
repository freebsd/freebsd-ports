--- src/VBox/Devices/USB/freebsd/USBProxyDevice-freebsd.cpp.orig	2025-08-13 19:49:01 UTC
+++ src/VBox/Devices/USB/freebsd/USBProxyDevice-freebsd.cpp
@@ -67,7 +67,7 @@
 #include "../USBProxyDevice.h"
 
 /** Maximum endpoints supported. */
-#define USBFBSD_MAXENDPOINTS 127
+#define USBFBSD_MAXENDPOINTS 126
 #define USBFBSD_MAXFRAMES 56
 
 /** This really needs to be defined in vusb.h! */
