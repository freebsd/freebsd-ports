--- usb2lpt.c.orig	2014-06-27 18:13:15.000000000 -0700
+++ usb2lpt.c	2014-06-27 18:13:45.000000000 -0700
@@ -47,7 +47,7 @@
 #if LIBUSB_VERSION == 1
 
 
-#include <libusb-1.0/libusb.h>
+#include <libusb.h>
 #else
 #include <usb.h>  
 #include "usbdefs.h"
