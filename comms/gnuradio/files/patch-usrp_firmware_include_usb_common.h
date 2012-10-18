--- usrp/firmware/include/usb_common.h.orig	2012-10-03 19:05:29.000000000 -0500
+++ usrp/firmware/include/usb_common.h	2012-10-03 19:05:52.000000000 -0500
@@ -23,7 +23,7 @@
 #ifndef _USB_COMMON_H_
 #define _USB_COMMON_H_
 
-extern volatile bit _usb_got_SUDAV;
+extern volatile __bit _usb_got_SUDAV;
 
 // Provided by user application to handle VENDOR commands.
 // returns non-zero if it handled the command.
