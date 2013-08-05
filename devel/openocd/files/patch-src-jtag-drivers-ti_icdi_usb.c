--- src/jtag/drivers/ti_icdi_usb.c.orig	2013-04-28 00:42:17.000000000 -0700
+++ src/jtag/drivers/ti_icdi_usb.c	2013-07-18 16:28:11.392443008 -0700
@@ -33,7 +33,7 @@
 
 #include <target/cortex_m.h>
 
-#include <libusb-1.0/libusb.h>
+#include <libusb.h>
 
 #define ICDI_WRITE_ENDPOINT 0x02
 #define ICDI_READ_ENDPOINT 0x83
