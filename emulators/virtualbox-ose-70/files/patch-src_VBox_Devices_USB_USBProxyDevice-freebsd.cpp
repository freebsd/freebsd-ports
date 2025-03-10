--- src/VBox/Devices/USB/freebsd/USBProxyDevice-freebsd.cpp.orig	2024-01-11 12:23:15 UTC
+++ src/VBox/Devices/USB/freebsd/USBProxyDevice-freebsd.cpp
@@ -57,7 +57,7 @@
 #include "../USBProxyDevice.h"
 
 /** Maximum endpoints supported. */
-#define USBFBSD_MAXENDPOINTS 127
+#define USBFBSD_MAXENDPOINTS 126
 #define USBFBSD_MAXFRAMES 56
 
 /** This really needs to be defined in vusb.h! */
