--- libsrc/conversion/im_tiff2vips.c.orig	Wed Aug 17 06:34:12 2005
+++ libsrc/conversion/im_tiff2vips.c
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
