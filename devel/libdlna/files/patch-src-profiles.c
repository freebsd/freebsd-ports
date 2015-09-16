--- src/profiles.c.orig	2007-11-26 21:47:43.000000000 +0100
+++ src/profiles.c	2015-07-03 22:44:50.380315167 +0200
@@ -204,14 +204,24 @@ av_profile_get_codecs (AVFormatContext *
 
   for (i = 0; i < ctx->nb_streams; i++)
   {
+#if LIBAVFORMAT_BUILD < 4621
     if (audio_stream == -1 &&
         ctx->streams[i]->codec->codec_type == CODEC_TYPE_AUDIO)
+#else
+    if (audio_stream == -1 &&
+        ctx->streams[i]->codec->codec_type == AVMEDIA_TYPE_AUDIO)
+#endif 
     {
       audio_stream = i;
       continue;
     }
+#if LIBAVFORMAT_BUILD < 4621
     else if (video_stream == -1 &&
              ctx->streams[i]->codec->codec_type == CODEC_TYPE_VIDEO)
+#else
+    else if (video_stream == -1 &&
+             ctx->streams[i]->codec->codec_type == AVMEDIA_TYPE_VIDEO)
+#endif
     {
       video_stream = i;
       continue;
@@ -280,14 +290,14 @@ dlna_guess_media_profile (dlna_t *dlna, 
   if (!dlna->inited)
     dlna = dlna_init ();
   
-  if (av_open_input_file (&ctx, filename, NULL, 0, NULL) != 0)
+  if (avformat_open_input (&ctx, filename, NULL, NULL) != 0)
   {
     if (dlna->verbosity)
       fprintf (stderr, "can't open file: %s\n", filename);
     return NULL;
   }
 
-  if (av_find_stream_info (ctx) < 0)
+  if (avformat_find_stream_info (ctx, NULL) < 0)
   {
     if (dlna->verbosity)
       fprintf (stderr, "can't find stream info\n");
@@ -334,7 +344,7 @@ dlna_guess_media_profile (dlna_t *dlna, 
     p = p->next;
   }
 
-  av_close_input_file (ctx);
+  avformat_close_input (ctx);
   free (codecs);
   return profile;
 }
