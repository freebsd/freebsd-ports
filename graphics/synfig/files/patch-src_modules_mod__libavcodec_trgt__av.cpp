--- src/modules/mod_libavcodec/trgt_av.cpp.orig	2022-12-24 14:01:41 UTC
+++ src/modules/mod_libavcodec/trgt_av.cpp
@@ -38,6 +38,7 @@
 extern "C"
 {
 #ifdef HAVE_LIBAVFORMAT_AVFORMAT_H
+#	include <libavcodec/avcodec.h>
 #	include <libavformat/avformat.h>
 #elif defined(HAVE_AVFORMAT_H)
 #	include <avformat.h>
@@ -234,12 +235,14 @@ class Target_LibAVCodec::Internal (public)
 		close();
 
 		if (!av_registered) {
-			av_register_all();
+#if LIBAVCODEC_VERSION_MAJOR < 59
+ 			av_register_all();
+#endif
 			av_registered = true;
 		}
 
 		// guess format
-		AVOutputFormat *format = av_guess_format(NULL, filename.c_str(), NULL);
+		const AVOutputFormat *format = av_guess_format(NULL, filename.c_str(), NULL);
 		if (!format) {
 			synfig::warning("Target_LibAVCodec: unable to guess the output format, defaulting to MPEG");
 			format = av_guess_format("mpeg", NULL, NULL);
@@ -254,7 +257,7 @@ class Target_LibAVCodec::Internal (public)
 		context = avformat_alloc_context();
 		assert(context);
 		context->oformat = format;
-		if (filename.size() + 1 > sizeof(context->filename)) {
+		/*if (filename.size() + 1 > sizeof(context->filename)) {
 			synfig::error(
 				"Target_LibAVCodec: filename too long, max length is %d, filename is '%s'",
 				sizeof(context->filename) - 1,
@@ -262,7 +265,13 @@ class Target_LibAVCodec::Internal (public)
 			close();
 			return false;
 		}
-		memcpy(context->filename, filename.c_str(), filename.size() + 1);
+		memcpy(context->filename, filename.c_str(), filename.size() + 1);*/
+		context->url = av_strndup(filename.c_str(), filename.size());
+		if (!context->url) {
+			synfig::error("Target_LibAVCodec: cannot allocate space for filename");
+			close();
+			return false;
+		}
 
 		packet = av_packet_alloc();
 		assert(packet);
