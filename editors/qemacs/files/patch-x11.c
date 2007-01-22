--- x11.c.orig	Tue Apr 22 07:01:42 2003
+++ x11.c	Thu Jan 18 13:57:10 2007
@@ -76,7 +76,7 @@
 static CSSRect update_rects[UPDATE_MAX_REGIONS];
 #endif
 
-extern QEDisplay x11_dpy;
+static QEDisplay x11_dpy;
 static int visual_depth;
 
 static int force_tty = 0;
