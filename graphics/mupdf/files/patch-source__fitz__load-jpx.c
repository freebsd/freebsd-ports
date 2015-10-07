--- source/fitz/load-jpx.c.orig	2015-04-16 08:57:45 UTC
+++ source/fitz/load-jpx.c
@@ -3,12 +3,17 @@
 /* Without the definition of OPJ_STATIC, compilation fails on windows
  * due to the use of __stdcall. We believe it is required on some
  * linux toolchains too. */
+
+#ifdef __cplusplus
+extern "C"
+{
 #define OPJ_STATIC
 #ifndef _MSC_VER
 #define OPJ_HAVE_STDINT_H
 #endif
+#endif
 
-#include <openjpeg.h>
+#include <openjpeg-2.1/openjpeg.h>
 
 static void fz_opj_error_callback(const char *msg, void *client_data)
 {
@@ -117,7 +122,7 @@ fz_load_jpx(fz_context *ctx, unsigned ch
 	opj_stream_set_read_function(stream, fz_opj_stream_read);
 	opj_stream_set_skip_function(stream, fz_opj_stream_skip);
 	opj_stream_set_seek_function(stream, fz_opj_stream_seek);
-	opj_stream_set_user_data(stream, &sb);
+	opj_stream_set_user_data(stream, &sb,NULL);
 	/* Set the length to avoid an assert */
 	opj_stream_set_user_data_length(stream, size);
 
@@ -247,3 +252,6 @@ fz_load_jpx(fz_context *ctx, unsigned ch
 
 	return img;
 }
+#ifdef __cplusplus
+}
+#endif
