--- libsrc/iofuncs/predicate.c.orig	Tue Feb  8 07:19:20 2005
+++ libsrc/iofuncs/predicate.c
@@ -73,6 +73,12 @@
 #include <vips/vips.h>
 
 #ifdef HAVE_TIFF
+#undef D50_X0
+#undef D50_Y0
+#undef D50_Z0
+#undef D65_X0
+#undef D65_Y0
+#undef D65_Z0
 #include <tiffio.h>
 #endif /*HAVE_TIFF*/
 
