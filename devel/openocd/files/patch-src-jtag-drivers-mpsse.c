--- src/jtag/drivers/mpsse.c.orig	2012-09-08 22:22:04.000000000 +0200
+++ src/jtag/drivers/mpsse.c	2012-09-08 22:22:14.000000000 +0200
@@ -24,7 +24,7 @@
 
 #include "mpsse.h"
 #include "helper/log.h"
-#include <libusb-1.0/libusb.h>
+#include <libusb.h>
 
 /* Compatibility define for older libusb-1.0 */
 #ifndef LIBUSB_CALL
