--- modules/media/src/main/native/gstreamer/gstreamer-lite/gstreamer/gst/gstregistry.c.orig	2019-07-23 04:09:55 UTC
+++ modules/media/src/main/native/gstreamer/gstreamer-lite/gstreamer/gst/gstregistry.c
@@ -143,7 +143,7 @@ static const int AVCODEC_LIBAV_EXPLICIT_VERSIONS[] = {
 // For ffmpeg (libavcodec-ffmpeg.so)
 static const int AVCODEC_FFMPEG_EXPLICIT_VERSIONS[] = { 56 };
 // For libav or ffmpeg (libavcodec.so)
-static const int AVCODEC_EXPLICIT_VERSIONS[] = { 57 };
+static const int AVCODEC_EXPLICIT_VERSIONS[] = { 58, 57 };
 
 /*
  * Callback passed to dl_iterate_phdr(): finds the path of
