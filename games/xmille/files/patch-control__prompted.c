--- control/prompted.c.orig	Tue Jul 12 03:01:02 1988
+++ control/prompted.c	Fri Jun 15 02:05:02 2007
@@ -9,6 +9,7 @@
 # include	"co_class.h"
 # include	<sys/time.h>
 # include	<assert.h>
+# include	<string.h>
 
 /*
  *	prompted window on screen
@@ -38,6 +39,17 @@
 
 static int	prompted_done;
 
+static int co_promptedEvent();
+static int co_OKstate();
+static int redisplayLabel();
+static int textbox_event();
+static int handle_char();
+static int compute_width();
+static int draw_char();
+static int draw_string();
+static int redisplayText();
+
+
 char *
 co_prompted(title, parent)
 char *title;
@@ -157,7 +169,7 @@
 		prompted_done = 1;
 		break;
 	case '\b':
-	case '\0177':
+	case 127:
 		if (retpointer > returnbuffer) {
 			c = *--retpointer;
 			*retpointer = '\0';
@@ -190,9 +202,10 @@
 draw_char (pos, ch, on)
 {
 	GC	my;
+	char    buf = ch;
 
 	my = on ? co_fore_gc : co_back_gc;
-	XDrawImageString (dpy, textbox, my, pos, TEXTBOX_VP, &ch, 1);
+	XDrawImageString (dpy, textbox, my, pos, TEXTBOX_VP, &buf, 1);
 }
 
 static
