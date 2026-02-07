--- pgdispd/updatelgtitle.c.orig	2020-08-31 12:24:15 UTC
+++ pgdispd/updatelgtitle.c
@@ -14,6 +14,7 @@
 #include "figdisp.h"
 #include "globals.h"
 #include <X11/Xlib.h>
+#include <stdio.h>
 #include <string.h>
 
 void updatelgtitle(x,y)
@@ -27,7 +28,7 @@ int x,y;	/* cursor position */
 	XImage *image;
 	int i;
 
-#ifndef _AIX
+#if !defined(_AIX) && !defined(__FreeBSD__)
 	char *sprintf();
 #endif
 
