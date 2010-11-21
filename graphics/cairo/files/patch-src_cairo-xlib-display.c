--- src/cairo-xlib-display.c.orig	2010-11-21 14:41:31.000000000 -0500
+++ src/cairo-xlib-display.c	2010-11-21 14:42:12.000000000 -0500
@@ -353,11 +353,7 @@ _cairo_xlib_device_create (Display *dpy)
     /* Prior to Render 0.10, there is no protocol support for gradients and
      * we call function stubs instead, which would silently consume the drawing.
      */
-#if RENDER_MAJOR == 0 && RENDER_MINOR < 10
     display->buggy_gradients = TRUE;
-#else
-    display->buggy_gradients = FALSE;
-#endif
     display->buggy_pad_reflect = FALSE;
     display->buggy_repeat = FALSE;
 
