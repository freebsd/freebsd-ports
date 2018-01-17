--- source/fitz/load-jpx.c.orig	2017-12-13 14:00:30 UTC
+++ source/fitz/load-jpx.c
@@ -445,14 +445,18 @@ fz_load_jpx_info(fz_context *ctx, const 
 
 #else /* HAVE_LURATECH */
 
+#ifdef __cplusplus
+extern "C"
+{
 #define OPJ_STATIC
 #define OPJ_HAVE_INTTYPES_H
 #if !defined(_MSC_VER) || _MSC_VER >= 1600
 #define OPJ_HAVE_STDINT_H
 #endif
+#endif
 #define USE_JPIP
 
-#include <openjpeg.h>
+#include <openjpeg-2.3/openjpeg.h>
 
 struct fz_jpxd_s
 {
@@ -930,6 +934,10 @@ fz_load_jpx_info(fz_context *ctx, const 
 	*yresp = state.yres;
 }
 
+#ifdef __cplusplus
+}
+#endif
+
 #endif /* HAVE_LURATECH */
 
 #else /* FZ_ENABLE_JPX */
