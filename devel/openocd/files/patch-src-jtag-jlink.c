--- src/jtag/jlink.c.orig	2009-07-13 23:29:38.000000000 +0200
+++ src/jtag/jlink.c	2010-02-12 11:08:50.000000000 +0100
@@ -891,6 +891,7 @@
 		 * test them carefully on all platforms before committing them!
 		 */
 
+#if 0
 #if IS_WIN32 == 0
 
 		usb_reset(result->usb_handle);
@@ -918,7 +919,7 @@
 
 		result->usb_handle = usb_open(dev);
 #endif
-
+#endif
 #endif
 
 		if (result->usb_handle)
