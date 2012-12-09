--- firmware/fx2/common/usb_common.h.orig	2012-07-30 14:09:48.000000000 -0500
+++ firmware/fx2/common/usb_common.h	2012-10-07 19:36:05.000000000 -0500
@@ -23,7 +23,7 @@
 #ifndef _USB_COMMON_H_
 #define _USB_COMMON_H_
 
-extern volatile bit _usb_got_SUDAV;
+extern volatile __bit _usb_got_SUDAV;
 
 // Provided by user application to handle VENDOR commands.
 // returns non-zero if it handled the command.
