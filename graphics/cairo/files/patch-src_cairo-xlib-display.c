--- src/cairo-xlib-display.c.orig	2008-03-13 20:52:38.000000000 -0400
+++ src/cairo-xlib-display.c	2008-03-13 20:53:29.000000000 -0400
@@ -302,6 +302,9 @@
 	    display->buggy_repeat = TRUE;
     }
 
+    /* XXX workaround; see https://bugzilla.mozilla.org/show_bug.cgi?id=413583 */
+    display->buggy_repeat = TRUE;
+
     display->next = _cairo_xlib_display_list;
     _cairo_xlib_display_list = display;
 
