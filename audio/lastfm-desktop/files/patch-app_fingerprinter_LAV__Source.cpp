--- app/fingerprinter/LAV_Source.cpp.orig	2013-09-03 12:19:10 UTC
+++ app/fingerprinter/LAV_Source.cpp
@@ -23,6 +23,10 @@
 #define __STDC_CONSTANT_MACROS 1
 #endif
 
+#ifndef AVCODEC_MAX_AUDIO_FRAME_SIZE
+#define AVCODEC_MAX_AUDIO_FRAME_SIZE 192000
+#endif
+
 extern "C" {
 #include <libavformat/avformat.h>
 #include <libavutil/mathematics.h>
@@ -113,7 +117,7 @@ uint8_t * LAV_SourcePrivate::decodeOneFr
 {
     char buf[256];
     AVPacket packet;
-    AVFrame *decodedFrame = avcodec_alloc_frame();
+    AVFrame *decodedFrame = av_frame_alloc();
     av_init_packet(&packet);
 
     int frameFinished = 0;
@@ -288,7 +292,7 @@ uint8_t * LAV_SourcePrivate::decodeOneFr
         av_free_packet(&packet);
     }
     timestamp += (double)nSamples / decodedFrame->sample_rate;
-    avcodec_free_frame(&decodedFrame);
+    av_frame_free(&decodedFrame);
     return outBuffer;
 }
 
@@ -405,7 +409,7 @@ void LAV_Source::getInfo(int& lengthSecs
 
 void LAV_Source::release()
 {
-    if ( d->inCodecContext && d->inCodecContext->codec_id != CODEC_ID_NONE )
+    if ( d->inCodecContext && d->inCodecContext->codec_id != AV_CODEC_ID_NONE )
     {
         avcodec_close(d->inCodecContext);
     }
