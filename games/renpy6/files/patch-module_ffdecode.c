https://github.com/renpy/renpy/commit/2be0638
https://github.com/renpy/renpy/commit/4aac7ca

--- module/ffdecode.c.orig	2014-07-06 14:22:40 UTC
+++ module/ffdecode.c
@@ -23,6 +23,7 @@
 #include <math.h>
 #include <limits.h>
 #include <libavutil/avstring.h>
+#include <libavutil/time.h>
 #include <libavformat/avformat.h>
 #include <libavcodec/avcodec.h>
 #include <libswscale/swscale.h>
@@ -101,8 +102,8 @@ typedef struct VideoState {
        compensation */
 
 #ifndef HAS_RESAMPLE
-    uint8_t audio_buf1[(AVCODEC_MAX_AUDIO_FRAME_SIZE * 3) / 2] __attribute__ ((aligned (16))) ;
-    uint8_t audio_buf2[(AVCODEC_MAX_AUDIO_FRAME_SIZE * 3) / 2] __attribute__ ((aligned (16))) ;
+    uint8_t audio_buf1[(192000 * 3) / 2] __attribute__ ((aligned (16))) ;
+    uint8_t audio_buf2[(192000 * 3) / 2] __attribute__ ((aligned (16))) ;
 #else
     uint8_t *audio_buf1;
 #endif
@@ -573,7 +574,7 @@ static int video_refresh(void *opaque)
 			video_display(is);
 		}
 
-		av_free(vp->frame);
+		av_frame_free(&vp->frame);
 		vp->frame = NULL;
 
 		is->first_frame = 0;
@@ -627,13 +628,13 @@ static void alloc_picture(void *opaque, 
 
     pixel = SDL_MapRGBA(surf->format, 1, 2, 3, 4);
     if (bytes[0] == 4 && bytes[1] == 1) {
-        vp->fmt = PIX_FMT_ARGB;
+        vp->fmt = AV_PIX_FMT_ARGB;
     } else if (bytes[0] == 4 && bytes[1] == 3) {
-        vp->fmt = PIX_FMT_ABGR;
+        vp->fmt = AV_PIX_FMT_ABGR;
     } else if (bytes[0] == 1) {
-        vp->fmt = PIX_FMT_RGBA;
+        vp->fmt = AV_PIX_FMT_RGBA;
     } else {
-        vp->fmt = PIX_FMT_BGRA;
+        vp->fmt = AV_PIX_FMT_BGRA;
     }
 
     pixel = SDL_MapRGBA(surf->format, 0, 0, 0, 255);
@@ -756,7 +757,7 @@ static int video_thread(void *arg)
     double pts;
 
     for(;;) {
-        frame = avcodec_alloc_frame();
+        frame = av_frame_alloc();
 
         while (is->paused && !is->videoq.abort_request) {
             SDL_Delay(2);
@@ -816,10 +817,10 @@ static int audio_decode_frame(VideoState
             int resample_changed, audio_resample;
 
             if (!is->frame) {
-                if (!(is->frame = avcodec_alloc_frame()))
+                if (!(is->frame = av_frame_alloc()))
                     return AVERROR(ENOMEM);
             } else
-                avcodec_get_frame_defaults(is->frame);
+                av_frame_unref(is->frame);
 
             if (flush_complete)
                 break;
@@ -836,7 +837,7 @@ static int audio_decode_frame(VideoState *is, double *
 
             if (!got_frame) {
                 /* stop sending empty packets if the decoder is finished */
-                if (!pkt_temp->data && dec->codec->capabilities & CODEC_CAP_DELAY)
+                if (!pkt_temp->data && dec->codec->capabilities & AV_CODEC_CAP_DELAY)
                     flush_complete = 1;
                 continue;
             }
@@ -1231,9 +1232,9 @@ static int stream_component_open(VideoSt
     /* prepare audio output */
     if (enc->codec_type == AVMEDIA_TYPE_AUDIO) {
         if (enc->channels > 0) {
-            enc->request_channels = FFMIN(2, enc->channels);
+            enc->request_channel_layout = av_get_default_channel_layout(FFMIN(2, enc->channels));
         } else {
-            enc->request_channels = 2;
+            enc->request_channel_layout = av_get_default_channel_layout(2);
         }
     }
 
@@ -1242,7 +1243,7 @@ static int stream_component_open(VideoState *is, int s
     enc->debug = debug;
     enc->workaround_bugs = workaround_bugs;
     enc->idct_algo= idct;
-    if(fast) enc->flags2 |= CODEC_FLAG2_FAST;
+    if(fast) enc->flags2 |= AV_CODEC_FLAG2_FAST;
     enc->skip_frame= skip_frame;
     enc->skip_idct= skip_idct;
     enc->skip_loop_filter= skip_loop_filter;
@@ -1633,7 +1634,7 @@ void ffpy_stream_close(VideoState *is)
     for(i=0; i<VIDEO_PICTURE_QUEUE_SIZE; i++) {
         vp = &is->pictq[i];
         if (vp->frame) {
-            av_free(vp->frame);
+            av_frame_free(&vp->frame);
         }
     }
 
