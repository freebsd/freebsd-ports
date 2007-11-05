--- src/display/idirectfbsurface.c.orig	2007-11-02 12:19:20.000000000 +0100
+++ src/display/idirectfbsurface.c	2007-11-02 12:27:33.000000000 +0100
@@ -298,9 +298,9 @@
      if (ret)
           return ret;
 
-     (__u8*)(*ptr) += data->area.current.y * (*pitch) +
-                      data->area.current.x *
-                      DFB_BYTES_PER_PIXEL(data->surface->format);
+     *ptr = (__u8 *)(*ptr) + (data->area.current.y * (*pitch) +
+                             data->area.current.x *
+                             DFB_BYTES_PER_PIXEL(data->surface->format));
 
      data->locked = front + 1;
 
