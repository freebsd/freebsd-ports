Author: Markus Koschany <apo@debian.org>
https://github.com/renpy/renpy/pull/829

--- module/ffdecode.c.orig	2015-03-21 15:29:24 UTC
+++ module/ffdecode.c
@@ -103,8 +103,8 @@ typedef struct VideoState {
        compensation */
 
 #ifndef HAS_RESAMPLE
-    uint8_t audio_buf1[(AVCODEC_MAX_AUDIO_FRAME_SIZE * 3) / 2] __attribute__ ((aligned (16))) ;
-    uint8_t audio_buf2[(AVCODEC_MAX_AUDIO_FRAME_SIZE * 3) / 2] __attribute__ ((aligned (16))) ;
+    uint8_t audio_buf1[(192000 * 3) / 2] __attribute__ ((aligned (16))) ;
+    uint8_t audio_buf2[(192000 * 3) / 2] __attribute__ ((aligned (16))) ;
 #else
     uint8_t *audio_buf1;
 #endif
@@ -583,7 +583,7 @@ static int video_refresh(void *opaque)
 
 		is->first_frame = 0;
 
-		av_free(vp->frame);
+		av_frame_free(&vp->frame);
 		vp->frame = NULL;
 
 		/* update queue size and signal for next picture */
@@ -635,13 +635,13 @@ static void alloc_picture(void *opaque, PyObject *pysurf)
 
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
@@ -764,7 +764,7 @@ static int video_thread(void *arg)
     double pts;
 
     for(;;) {
-        frame = avcodec_alloc_frame();
+        frame = av_frame_alloc();
 
         while (is->paused && !is->videoq.abort_request) {
             SDL_Delay(2);
@@ -824,10 +824,10 @@ static int audio_decode_frame(VideoState *is, double *pts_ptr)
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
@@ -1244,9 +1244,9 @@ static int stream_component_open(VideoState *is, int stream_index)
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
 
@@ -1653,7 +1653,7 @@ void ffpy_stream_close(VideoState *is)
     for(i=0; i<VIDEO_PICTURE_QUEUE_SIZE; i++) {
         vp = &is->pictq[i];
         if (vp->frame) {
-            av_free(vp->frame);
+            av_frame_free(&vp->frame);
         }
     }
 
