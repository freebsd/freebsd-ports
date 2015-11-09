--- src/cairo-xlib-display.c.orig	2015-03-10 22:21:07 UTC
+++ src/cairo-xlib-display.c
@@ -263,11 +263,7 @@ _cairo_xlib_device_create (Display *dpy)
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
 
