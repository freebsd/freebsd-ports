--- src/arch/unix/joy_usb.c.orig	Tue Feb 20 10:11:57 2007
+++ src/arch/unix/joy_usb.c	Tue Feb 20 10:12:37 2007
@@ -50,6 +50,7 @@
 
 extern log_t joystick_log;
 
+#include <sys/ioccom.h>
 #include <dev/usb/usb.h>
 #include <dev/usb/usbhid.h>
 #include <errno.h>
