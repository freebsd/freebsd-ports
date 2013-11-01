--- src/x/xkeyboard.c.orig	2010-12-08 09:13:50.000000000 +0100
+++ src/x/xkeyboard.c	2013-07-28 00:17:52.000000000 +0200
@@ -23,6 +23,7 @@
 #include <X11/Xos.h>
 #include <X11/Xlib.h>
 #include <X11/Xutil.h>
+#include <X11/XKBlib.h>
 #include <X11/Xproto.h>
 
 #include "allegro.h"
@@ -617,7 +618,7 @@
 
       TRACE (PREFIX_I "Modifier %d:", i + 1);
       for (j = 0; j < xmodmap->max_keypermod; j++) {
-	 KeySym sym = XKeycodeToKeysym(_xwin.display,
+	 KeySym sym = XkbKeycodeToKeysym(_xwin.display, 0,
 	    xmodmap->modifiermap[i * xmodmap->max_keypermod + j], 0);
          char *sym_str = XKeysymToString(sym);
          TRACE(" %s", sym_str ? sym_str : "NULL");
