--- vid_enc_ffmpeg/gap_enc_ffmpeg_main.c.orig	2007-08-22 09:48:40.000000000 -0400
+++ vid_enc_ffmpeg/gap_enc_ffmpeg_main.c	2007-08-22 09:55:11.000000000 -0400
@@ -1537,8 +1537,8 @@
 
   video_enc->bit_rate = epp->video_bitrate * 1000;
   video_enc->bit_rate_tolerance = epp->bitrate_tol * 1000;
-  video_enc->frame_rate_base = DEFAULT_FRAME_RATE_BASE;
-  video_enc->frame_rate = gpp->val.framerate * DEFAULT_FRAME_RATE_BASE;
+  video_enc->time_base.den = DEFAULT_FRAME_RATE_BASE;
+  video_enc->time_base.num = gpp->val.framerate * DEFAULT_FRAME_RATE_BASE;
   video_enc->width = gpp->val.vid_width;
   video_enc->height = gpp->val.vid_height;
 
@@ -2235,12 +2235,11 @@
    */
   ffh->ap->sample_rate = awp->awk[0].sample_rate;
   ffh->ap->channels = awp->awk[0].channels;
-  ffh->ap->frame_rate_base = DEFAULT_FRAME_RATE_BASE;
-  ffh->ap->frame_rate = gpp->val.framerate * DEFAULT_FRAME_RATE_BASE;
+  ffh->ap->time_base.num = DEFAULT_FRAME_RATE_BASE;
+  ffh->ap->time_base.den = gpp->val.framerate * DEFAULT_FRAME_RATE_BASE;
   ffh->ap->width = gpp->val.vid_width;
   ffh->ap->height = gpp->val.vid_height;
 
-  ffh->ap->image_format = NULL;
   ffh->ap->pix_fmt = PIX_FMT_YUV420P;
 
   /* tv standard, NTSC, PAL, SECAM */
