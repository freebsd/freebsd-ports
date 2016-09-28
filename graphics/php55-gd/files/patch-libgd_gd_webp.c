--- libgd/gd_webp.c.orig	2016-09-28 10:07:06.092196000 +0200
+++ libgd/gd_webp.c	2016-09-28 10:08:12.429030000 +0200
@@ -180,6 +180,15 @@ void gdImageWebpCtx (gdImagePtr im, gdIO
 	/* Conversion to Y,U,V buffer */
     yuv_width = (width + 1) >> 1;
     yuv_height = (height + 1) >> 1;
+
+    if (overflow2(width, height)) {
+        return;
+    }
+    /* simplification possible, because WebP must not be larger than 16384**2 */
+    if (overflow2(width * height, 2 * sizeof(unsigned char))) {
+        return;
+    }
+
     yuv_nbytes = width * height + 2 * yuv_width * yuv_height;
 
     if ((Y = (unsigned char *)gdCalloc(yuv_nbytes, sizeof(unsigned char))) == NULL) {
