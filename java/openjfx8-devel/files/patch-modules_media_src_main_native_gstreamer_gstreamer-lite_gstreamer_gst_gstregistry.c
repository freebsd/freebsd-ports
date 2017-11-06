--- modules/media/src/main/native/gstreamer/gstreamer-lite/gstreamer/gst/gstregistry.c.orig	2017-10-04 12:06:08 UTC
+++ modules/media/src/main/native/gstreamer/gstreamer-lite/gstreamer/gst/gstregistry.c
@@ -162,7 +162,7 @@ extern HMODULE _priv_gst_dll_handle;
 #include <link.h>
 #include <dlfcn.h>
 
-static const int AVCODEC_EXPLICIT_VERSIONS[] = { 53, 54, 55, 56 };
+static const int AVCODEC_EXPLICIT_VERSIONS[] = { 53, 54, 55, 56, 57 };
 static const int AVCODEC_FFMPEG_EXPLICIT_VERSIONS[] = { 56 };
 
 typedef unsigned (*avcodec_version_proto)();
