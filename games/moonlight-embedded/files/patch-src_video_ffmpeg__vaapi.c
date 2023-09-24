--- src/video/ffmpeg_vaapi.c.orig	2023-09-01 23:40:56 UTC
+++ src/video/ffmpeg_vaapi.c
@@ -23,6 +23,7 @@
 #include <libavutil/hwcontext.h>
 #include <libavutil/hwcontext_vaapi.h>
 #include <X11/Xlib.h>
+#include <stdlib.h>
 
 #define MAX_SURFACES 16
 
@@ -59,7 +60,7 @@ static int va_get_buffer(AVCodecContext* context, AVFr
 }
 
 int vaapi_init_lib() {
-  return av_hwdevice_ctx_create(&device_ref, AV_HWDEVICE_TYPE_VAAPI, ":0", NULL, 0);
+  return av_hwdevice_ctx_create(&device_ref, AV_HWDEVICE_TYPE_VAAPI, getenv("DISPLAY") == NULL ? ":0" : getenv("DISPLAY"), NULL, 0);
 }
 
 int vaapi_init(AVCodecContext* decoder_ctx) {
