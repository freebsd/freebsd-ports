--- test/test_libhid.c.orig	2009-03-07 20:29:59.000000000 +0300
+++ test/test_libhid.c	2009-03-07 20:30:05.000000000 +0300
@@ -1,5 +1,6 @@
 #include <hid.h>
 #include <stdio.h>
+#include <stdlib.h>
 #include <string.h>
 
 bool match_serial_number(struct usb_dev_handle* usbdev, void* custom, unsigned int len)
