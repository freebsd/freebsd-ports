--- libvips/format/im_tiff2vips.c	Wed Aug 17 06:34:12 2005
+++ libvips/format/im_tiff2vips.c
@@ -157,6 +157,12 @@
 #include <vips/vips.h>
 #include <vips/thread.h>
 
+#undef D50_X0
+#undef D50_Y0
+#undef D50_Z0
+#undef D65_X0
+#undef D65_Y0
+#undef D65_Z0
 #include <tiffio.h>
 
 #ifdef WITH_DMALLOC
