--- src/platform/usbjoy.cxx.orig	Thu Nov 15 02:27:11 2001
+++ src/platform/usbjoy.cxx		Sat Jan 26 05:48:50 2002
@@ -46,7 +46,7 @@
 	int data_buf_offset;
 };
 
-usb_joystick *stick;
+usb_joystick *stick=NULL;
 
 usb_joystick::usb_joystick(const char *name)
 {
