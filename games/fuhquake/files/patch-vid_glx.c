--- vid_glx.c.orig	Thu Aug 28 18:08:22 2003
+++ vid_glx.c	Thu Aug 28 18:08:03 2003
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
@@ -284,8 +286,8 @@
 	case MotionNotify:
 #ifdef WITH_DGA
 		if (dgamouse && _windowed_mouse.value) {
-			mouse_x = event.xmotion.x_root;
-			mouse_y = event.xmotion.y_root;
+			mouse_x += event.xmotion.x_root;
+			mouse_y += event.xmotion.y_root;
 		} else
 #endif
 		{
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
