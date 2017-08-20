--- source/fitz/load-jpx.c.orig	2017-04-05 11:02:21 UTC
+++ source/fitz/load-jpx.c
@@ -444,14 +444,18 @@ fz_load_jpx_info(fz_context *ctx, unsign
 
 #else /* HAVE_LURATECH */
 
+#ifdef __cplusplus
+extern "C"
+{
 #define OPJ_STATIC
 #define OPJ_HAVE_INTTYPES_H
 #if !defined(_WIN32) && !defined(_WIN64)
 #define OPJ_HAVE_STDINT_H
 #endif
+#endif
 #define USE_JPIP
 
-#include <openjpeg.h>
+#include <openjpeg-2.2/openjpeg.h>
 
 struct fz_jpxd_s
 {
@@ -919,6 +923,10 @@ fz_load_jpx_info(fz_context *ctx, unsign
 	*yresp = state.yres;
 }
 
+#ifdef __cplusplus
+}
+#endif
+
 #endif /* HAVE_LURATECH */
 
 #else /* FZ_ENABLE_JPX */
