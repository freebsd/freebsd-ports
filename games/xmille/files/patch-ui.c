--- ui.c.orig	Tue Apr  2 12:55:55 1996
+++ ui.c	Fri Jun 15 02:20:34 2007
@@ -7,6 +7,8 @@
 # include	"mille.h"
 # include	"ui.h"
 # include	<X11/Xutil.h>
+# include	<string.h>
+# include	<stdlib.h>
 
 #ifdef CTRL
 # undef CTRL
@@ -84,7 +86,9 @@
 		return(orig);
 	if (XTextWidth (font, orig, len) < max)
 		return orig;
-	strcpy (buf, orig);
+	if (len > sizeof(buf))
+	    len = sizeof(buf);
+	strncpy (buf, orig, len);
 	do {
 		buf[--len] = '\0';
 	} while (len > 0 && XTextWidth (font, buf, len) >= max);
@@ -409,6 +413,10 @@
 	Colormap	def_cm;
 
 	dpy = XOpenDisplay ((char *) 0);
+	if (!dpy) {
+		printf("Error: Can't open X Display\n");
+		exit(1);
+	}
 	screen = DefaultScreen(dpy);
 	def_cm = DefaultColormap(dpy, screen);
 	
