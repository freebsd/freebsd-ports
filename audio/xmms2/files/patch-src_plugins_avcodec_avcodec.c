--- src/plugins/avcodec/avcodec.c.orig	2013-10-25 14:04:33.493859184 -0200
+++ src/plugins/avcodec/avcodec.c	2013-10-25 14:08:39.342858585 -0200
@@ -28,6 +28,10 @@
 
 #define AVCODEC_BUFFER_SIZE 16384
 
+#ifndef AVCODEC_MAX_AUDIO_FRAME_SIZE
+#define AVCODEC_MAX_AUDIO_FRAME_SIZE 192000 // 1 second of 48khz 32bit audio
+#endif
+
 typedef struct {
 	AVCodecContext *codecctx;
 
