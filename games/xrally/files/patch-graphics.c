--- graphics.c.orig	2000-12-09 04:42:47.000000000 +1100
+++ graphics.c	2009-02-22 14:41:51.000000000 +1100
@@ -5,7 +5,7 @@
     copyright            : (C) 2000 by Perdig
     email                : perdig@linuxbr.com.br
 
-    $Id: graphics.c,v 1.15 2000/12/07 12:44:10 perdig Exp $
+    $Id: graphics.c,v 1.16 2001/01/11 15:28:03 perdig Exp $
  ***************************************************************************/
 
 /***************************************************************************
@@ -18,12 +18,14 @@
  ***************************************************************************/
 #include "graphics.h"
 #include "global.h"
+#include <unistd.h>
+#include <string.h>
 #include <sys/time.h>
 
 // Internal functions
 
 static char ** _split_text(const char *_txt);
-static int _check_event(XEvent *xev);
+static int _check_event(XEvent *xev, int blocking);
 long time_diff(struct timeval *rt);
 
 // Basic X11 variables
@@ -401,10 +403,15 @@
 	return double_buffer;
 }
 
-static int _check_event(XEvent *xev) {
+static int _check_event(XEvent *xev, int blocking) {
 	XEvent *last = NULL;
+  int a = 0;
 
-	while (XCheckMaskEvent(dpy, KeyPressMask | ExposureMask, xev)) {
+	do {
+    if (blocking)
+      XWindowEvent(dpy, win, KeyPressMask | ExposureMask, xev);
+    else
+      a = XCheckMaskEvent(dpy, KeyPressMask | ExposureMask, xev);
 		switch (xev->type) {
 			case KeyPress:
 				last = xev;
@@ -417,7 +424,7 @@
 			default:
 				break;
 		}
-	}
+	} while ((blocking && !last) || (!blocking && a));
 	// No events
 	xev = last;
 	return (last) ? true : false;
@@ -426,32 +433,35 @@
 
 KeySym check_key() {
 	XEvent xev;
-	if (_check_event(&xev) && xev.type == KeyPress)
+	if (_check_event(&xev, 0) && xev.type == KeyPress)
 		return XLookupKeysym(&xev.xkey, 0);
 	// No events
 	return XK_VoidSymbol;
 }
 
 KeySym wait_key() {
-	KeySym key = XK_VoidSymbol;
-	while (key == XK_VoidSymbol) {
-		key = check_key();
-	}
-	return key;
+  XEvent xev;
+  _check_event(&xev, 1);
+  return XLookupKeysym(&xev.xkey, 0);
 }
 
 void wait_time(long time_wait) {
-	struct timeval it;
+	struct timeval it, tmp;
 	XEvent xev;
 	gettimeofday(&it, NULL);
-	while (time_diff(&it) < time_wait)
-		_check_event(&xev);
+	while (time_diff(&it) < time_wait) {
+    /* Reduce system load, sleeping for a while */
+    tmp.tv_sec = 0;
+    tmp.tv_usec = 1000;
+    select(0, NULL, NULL, NULL, &tmp);
+		_check_event(&xev, 0);
+  }
 }
 
 KeySym wait_char(char *str) {
 	KeySym key = XK_VoidSymbol;
 	XEvent xev;
-	while (!_check_event(&xev) || xev.type != KeyPress);
+	_check_event(&xev, 1);
 	XLookupString(&xev.xkey, str, 3, &key,  NULL);
 	return key;
 }
