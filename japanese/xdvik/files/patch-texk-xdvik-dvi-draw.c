--- xdvik-22.40w/texk/xdvik/dvi-draw.c.orig	Sat May 12 15:00:41 2007
+++ xdvik-22.40w/texk/xdvik/dvi-draw.c	Sat May 12 15:01:18 2007
@@ -522,7 +522,7 @@
 
 #endif /* T1LIB */
 
-extern void home();  /* from events.c */
+extern void home ARGS((wide_bool go_home));  /* from events.c */
 extern int fallbacktfm; /* from tfmload.c */
 
 static struct frame frame0;	/* dummy head of list */
