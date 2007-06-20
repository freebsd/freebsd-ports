--- control/dispatch.c.orig	Tue Jul 12 02:11:32 1988
+++ control/dispatch.c	Fri Jun 15 02:05:02 2007
@@ -5,6 +5,7 @@
  */
 
 # include	<X11/Xlib.h>
+# include	<stdlib.h>
 
 struct eventGroup {
 	struct eventGroup	*prev;
@@ -54,9 +55,12 @@
 };
 
 
-struct eventGroup	*eventStack, *allocGroup();
+struct eventGroup	*eventStack;
 extern	Display		*dpy;
 
+static struct eventGroup* allocGroup();
+
+
 bindEvent (window, eventMask, func)
 Window		window;
 unsigned long	eventMask;
@@ -135,8 +139,6 @@
 static struct eventGroup *
 allocGroup ()
 {
-	char	*malloc ();
-
 	return (struct eventGroup *) malloc (sizeof (struct eventGroup));
 }
 
