--- vid_glx.c.orig	Wed May 21 17:18:37 2003
+++ vid_glx.c	Mon Jun  2 20:04:34 2003
@@ -20,7 +20,9 @@
 #include <termios.h>
 #include <sys/ioctl.h>
 #include <sys/stat.h>
+#ifdef __linux__
 #include <sys/vt.h>
+#endif
 #include <stdarg.h>
 #include <stdio.h>
 #include <signal.h>
@@ -601,8 +603,9 @@
 #ifdef WITH_VMODE
 	// fullscreen
 	if (vidmode_active) {
-		mask = CWBackPixel | CWColormap | CWSaveUnder | CWBackingStore | CWEventMask;
+		mask = CWBackPixel | CWColormap | CWSaveUnder | CWBackingStore | CWEventMask | CWOverrideRedirect;
 		attr.backing_store = NotUseful;
+		attr.override_redirect = True;
 		attr.save_under = False;
 	}
 #endif
