ffmpegdrv.c:363:34: error: use of undeclared identifier 'CODEC_CAP_VARIABLE_FRAME_SIZE'
    if (c->codec->capabilities & CODEC_CAP_VARIABLE_FRAME_SIZE) {
                                 ^
ffmpegdrv.c:457:21: error: use of undeclared identifier 'CODEC_FLAG_GLOBAL_HEADER'
        c->flags |= CODEC_FLAG_GLOBAL_HEADER;
                    ^
ffmpegdrv.c:790:21: error: use of undeclared identifier 'CODEC_FLAG_GLOBAL_HEADER'
        c->flags |= CODEC_FLAG_GLOBAL_HEADER;
                    ^
ffmpegdrv.c:970:40: error: use of undeclared identifier 'AVFMT_RAWPICTURE'
    if (ffmpegdrv_oc->oformat->flags & AVFMT_RAWPICTURE) {
                                       ^

--- src/gfxoutputdrv/ffmpegdrv.c.orig	2017-03-30 20:32:40 UTC
+++ src/gfxoutputdrv/ffmpegdrv.c
@@ -360,7 +360,7 @@ static int ffmpegdrv_open_audio(AVFormatContext *oc, A
     }
 
     audio_is_open = 1;
-    if (c->codec->capabilities & CODEC_CAP_VARIABLE_FRAME_SIZE) {
+    if (c->codec->capabilities & AV_CODEC_CAP_VARIABLE_FRAME_SIZE) {
         audio_inbuf_samples = 10000;
     } else {
         audio_inbuf_samples = c->frame_size;
@@ -454,7 +454,7 @@ static int ffmpegmovie_init_audio(int speed, int chann
 
     /* Some formats want stream headers to be separate. */
     if (ffmpegdrv_oc->oformat->flags & AVFMT_GLOBALHEADER)
-        c->flags |= CODEC_FLAG_GLOBAL_HEADER;
+        c->flags |= AV_CODEC_FLAG_GLOBAL_HEADER;
 
     /* create resampler context */
 #ifndef HAVE_FFMPEG_AVRESAMPLE
@@ -787,7 +787,7 @@ static void ffmpegdrv_init_video(screenshot_t *screens
 
     /* Some formats want stream headers to be separate. */
     if (ffmpegdrv_oc->oformat->flags & AVFMT_GLOBALHEADER) {
-        c->flags |= CODEC_FLAG_GLOBAL_HEADER;
+        c->flags |= AV_CODEC_FLAG_GLOBAL_HEADER;
     }
 
     if (audio_init_done) {
@@ -967,6 +967,7 @@ static int ffmpegdrv_record(screenshot_t *screenshot)
 
     video_st.frame->pts = video_st.next_pts++;
 
+#ifdef AVFMT_RAWPICTURE
     if (ffmpegdrv_oc->oformat->flags & AVFMT_RAWPICTURE) {
         AVPacket pkt;
         VICE_P_AV_INIT_PACKET(&pkt);
@@ -977,7 +978,9 @@ static int ffmpegdrv_record(screenshot_t *screenshot)
         pkt.pts = pkt.dts = video_st.frame->pts;
 
         ret = VICE_P_AV_INTERLEAVED_WRITE_FRAME(ffmpegdrv_oc, &pkt);
-    } else {
+    } else
+#endif
+    {
         AVPacket pkt = { 0 };
         int got_packet;
 
