--- src/develop/imageop_math.c.orig	2017-01-27 11:03:43 UTC
+++ src/develop/imageop_math.c
@@ -195,13 +195,13 @@ void dt_iop_clip_and_zoom_mosaic_half_si
 
     const float fy = (y + roi_out->y) * px_footprint;
     const int miny = CLAMPS((int)floorf(fy - px_footprint), 0, roi_in->height-3);
-    const int maxy = MIN(roi_in->height-1, (int)ceilf(fy + px_footprint));
+    const int maxy = MIN(roi_in->height-2, (int)ceilf(fy + px_footprint));
 
     float fx = roi_out->x * px_footprint;
     for(int x = 0; x < roi_out->width; x++, fx += px_footprint, outc++)
     {
       const int minx = CLAMPS((int)floorf(fx - px_footprint), 0, roi_in->width-3);
-      const int maxx = MIN(roi_in->width-1, (int)ceilf(fx + px_footprint));
+      const int maxx = MIN(roi_in->width-2, (int)ceilf(fx + px_footprint));
 
       const int c = FC(y, x, filters);
       int num = 0;
