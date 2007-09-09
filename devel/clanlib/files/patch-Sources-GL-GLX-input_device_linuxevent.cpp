--- Sources/GL/GLX/input_device_linuxevent.cpp.orig	Tue Oct 25 12:39:25 2005
+++ Sources/GL/GLX/input_device_linuxevent.cpp	Tue May  1 05:55:26 2007
@@ -26,7 +26,7 @@
 **    Magnus Norddahl
 **    (if your name is missing here, please add it)
 */
-
+#if 0
 #include <assert.h>
 #include <linux/input.h>
 #include <sys/ioctl.h>
@@ -350,3 +350,4 @@
 // Local Variables: ***
 // mode: clanlib ***
 // End: ***
+#endif
