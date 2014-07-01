--- si570.c.orig	2014-06-27 18:12:23.000000000 -0700
+++ si570.c	2014-06-27 18:12:39.000000000 -0700
@@ -376,7 +376,7 @@
 #if LIBUSB_VERSION == 1
 
 
-#include <libusb-1.0/libusb.h>
+#include <libusb.h>
 
 
 libusb_device_handle  *global_si570usb_handle = NULL;
