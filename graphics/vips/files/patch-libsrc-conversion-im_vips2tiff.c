--- libsrc/conversion/im_vips2tiff.c.orig	Fri Mar  3 03:06:32 2006
+++ libsrc/conversion/im_vips2tiff.c
@@ -145,6 +145,12 @@
 
 #include <vips/vips.h>
 
+#undef D50_X0
+#undef D50_Y0
+#undef D50_Z0
+#undef D65_X0
+#undef D65_Y0
+#undef D65_Z0
 #include <tiffio.h>
 
 #ifdef WITH_DMALLOC
