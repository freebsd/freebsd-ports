--- ./source/fitz/load-jpx.c.orig	2014-06-10 17:09:28.000000000 +0200
+++ ./source/fitz/load-jpx.c	2014-08-04 18:51:45.000000000 +0200
@@ -8,7 +8,7 @@
 #define OPJ_HAVE_STDINT_H
 #endif
 
-#include <openjpeg.h>
+#include <openjpeg-2.1/openjpeg.h>
 
 static void fz_opj_error_callback(const char *msg, void *client_data)
 {
@@ -116,7 +116,7 @@
 	opj_stream_set_read_function(stream, fz_opj_stream_read);
 	opj_stream_set_skip_function(stream, fz_opj_stream_skip);
 	opj_stream_set_seek_function(stream, fz_opj_stream_seek);
-	opj_stream_set_user_data(stream, &sb);
+	opj_stream_set_user_data(stream, &sb,NULL);
 	/* Set the length to avoid an assert */
 	opj_stream_set_user_data_length(stream, size);
 
