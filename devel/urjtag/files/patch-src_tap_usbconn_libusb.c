--- src/tap/usbconn/libusb.c.orig	2020-01-11 20:59:55 UTC
+++ src/tap/usbconn/libusb.c
@@ -40,6 +40,8 @@
 #include "libusb.h"
 #include "../usbconn.h"
 
+extern const urj_usbconn_driver_t urj_tap_usbconn_libusb_driver;
+
 /* ---------------------------------------------------------------------- */
 
 /* @return 1 when found, 0 when not */
