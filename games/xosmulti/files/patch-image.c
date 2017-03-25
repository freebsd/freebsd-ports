--- image.c.orig	2017-03-22 15:54:32 UTC
+++ image.c
@@ -6,6 +6,7 @@
 
 #include	<stdio.h>
 #include	<stdlib.h>
+#include	<string.h>
 
 #include	<X11/Xlib.h>
 #include	<X11/Xutil.h>
@@ -44,6 +45,7 @@ unsigned int	GetXDepth( disp )
 	Display	*disp;
 {
 
+	return DefaultDepth(disp, 0);
 	XVisualInfo	xvi_template;
 	XVisualInfo	*p_xvi;
 	int		n_item, i;
