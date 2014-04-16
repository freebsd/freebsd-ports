--- src/gfxoutputdrv/ffmpegdrv.c.orig	2012-02-13 20:31:44.000000000 +0100
+++ src/gfxoutputdrv/ffmpegdrv.c	2012-11-25 13:10:46.712199998 +0100
@@ -343,7 +343,7 @@ static int ffmpegmovie_init_audio(int sp
     c = st->codec;
     c->codec_id = ffmpegdrv_fmt->audio_codec;
     c->codec_type = AVMEDIA_TYPE_AUDIO;
-    c->sample_fmt = SAMPLE_FMT_S16;
+    c->sample_fmt = AV_SAMPLE_FMT_S16;
 
     /* put sample parameters */
     c->bit_rate = audio_bitrate;
@@ -613,11 +613,6 @@ static int ffmpegdrv_init_file(void)
     if (!video_init_done || !audio_init_done)
         return 0;
 
-    if ((*ffmpeglib.p_av_set_parameters)(ffmpegdrv_oc, NULL) < 0) {
-        log_debug("ffmpegdrv: Invalid output format parameters");
-            return -1;
-    }
-
     (*ffmpeglib.p_dump_format)(ffmpegdrv_oc, 0, ffmpegdrv_oc->filename, 1);
 
     if (video_st && (ffmpegdrv_open_video(ffmpegdrv_oc, video_st) < 0)) {
@@ -632,8 +627,8 @@ static int ffmpegdrv_init_file(void)
     }
 
     if (!(ffmpegdrv_fmt->flags & AVFMT_NOFILE)) {
-        if ((*ffmpeglib.p_url_fopen)(&ffmpegdrv_oc->pb, ffmpegdrv_oc->filename,
-                            URL_WRONLY) < 0) 
+        if ((*ffmpeglib.p_avio_open)(&ffmpegdrv_oc->pb, ffmpegdrv_oc->filename,
+                            AVIO_FLAG_WRITE) < 0) 
         {
             ui_error(translate_text(IDGS_FFMPEG_CANNOT_OPEN_S), ffmpegdrv_oc->filename);
             screenshot_stop_recording();
@@ -642,7 +637,7 @@ static int ffmpegdrv_init_file(void)
 
     }
 
-    (*ffmpeglib.p_av_write_header)(ffmpegdrv_oc);
+    (*ffmpeglib.p_avformat_write_header)(ffmpegdrv_oc, NULL);
 
     log_debug("ffmpegdrv: Initialized file successfully");
 
@@ -724,7 +719,7 @@ static int ffmpegdrv_close(screenshot_t
         (*ffmpeglib.p_av_write_trailer)(ffmpegdrv_oc);
         if (!(ffmpegdrv_fmt->flags & AVFMT_NOFILE)) {
             /* close the output file */
-            (*ffmpeglib.p_url_fclose)(ffmpegdrv_oc->pb);
+            (*ffmpeglib.p_avio_close)(ffmpegdrv_oc->pb);
         }
     }
     
