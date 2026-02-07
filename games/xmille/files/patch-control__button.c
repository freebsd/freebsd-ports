--- control/button.c.orig	Thu Apr  2 23:06:52 1992
+++ control/button.c	Fri Jun 15 02:05:02 2007
@@ -5,6 +5,8 @@
 # include	<X11/Xlib.h>
 # include	<X11/Xutil.h>
 # include	"control.h"
+# include	<string.h>
+# include	<stdlib.h>
 
 extern	Display	*dpy;
 
@@ -31,6 +33,12 @@
 static XContext	perwindowContext;
 static int		nextButton;
 
+static int buttonOn();
+static int buttonOff();
+static int buttonText();
+
+
+
 Button
 CcreateButton (text, width, gc, font, backcolor, borderwidth)
 char		*text;
@@ -40,7 +48,6 @@
 long		backcolor;
 int		borderwidth;
 {
-	char		*malloc ();
 	struct button	*b;
 	int		round, off;
 	int		hround;
