--- operations/external/ff-save.c.orig	2017-07-01 17:19:54 UTC
+++ operations/external/ff-save.c
@@ -290,7 +290,7 @@ add_audio_stream (GeglProperties *o, AVFormatContext *
   c->codec_type = AVMEDIA_TYPE_AUDIO;
 
   if (oc->oformat->flags & AVFMT_GLOBALHEADER)
-    c->flags |= CODEC_FLAG_GLOBAL_HEADER;
+    c->flags |= AV_CODEC_FLAG_GLOBAL_HEADER;
 
   return st;
 }
@@ -631,7 +631,7 @@ add_video_stream (GeglProperties *o, AVFormatContext *
 #endif
 
    if (oc->oformat->flags & AVFMT_GLOBALHEADER)
-     c->flags |= CODEC_FLAG_GLOBAL_HEADER;
+     c->flags |= AV_CODEC_FLAG_GLOBAL_HEADER;
 
   return st;
 }
@@ -699,7 +699,9 @@ open_video (GeglProperties *o, AVFormatContext * oc, A
     }
 
   p->video_outbuf = NULL;
+#ifdef AVFMT_RAWPICTURE
   if (!(oc->oformat->flags & AVFMT_RAWPICTURE))
+#endif
     {
       /* allocate output buffer, 1 mb / frame, might fail for some codecs on UHD - but works for now */
       p->video_outbuf_size = 1024 * 1024;
@@ -803,6 +805,7 @@ write_video_frame (GeglProperties *o,
   picture_ptr      = p->picture;
   picture_ptr->pts = p->frame_count;
 
+#ifdef AVFMT_RAWPICTURE
   if (oc->oformat->flags & AVFMT_RAWPICTURE)
     {
       /* raw video case. The API will change slightly in the near
@@ -821,6 +824,7 @@ write_video_frame (GeglProperties *o,
       ret = av_write_frame (oc, &pkt);
     }
   else
+#endif
     {
       /* encode the image */
       AVPacket pkt2;
