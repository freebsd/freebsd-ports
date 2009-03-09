--- gamepad_usbhid.c.orig	2009-03-08 12:35:35.000000000 +0300
+++ gamepad_usbhid.c	2009-03-08 12:35:44.000000000 +0300
@@ -3,6 +3,7 @@
 #include <string.h>
 #include <sys/ioctl.h>
 #include <dev/usb/usb.h>
+#include <dev/usb/usb_ioctl.h>
 #include <errno.h>
 #include <fcntl.h>
 #include <unistd.h>
