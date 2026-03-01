--- src/decode.c.orig	2026-03-01 17:09:43 UTC
+++ src/decode.c
@@ -66,8 +66,10 @@ int bl_audio_decode(char const *const filename, struct
   }
 
   // Find stream and corresponding codec
+  const AVCodec *codec_const = NULL;
   audio_stream =
-      av_find_best_stream(context, AVMEDIA_TYPE_AUDIO, -1, -1, &codec, 0);
+      av_find_best_stream(context, AVMEDIA_TYPE_AUDIO, -1, -1, &codec_const, 0);
+  codec = (AVCodec *)codec_const;
   if (audio_stream < 0) {
     fprintf(stderr, "Couldn't find a suitable audio stream\n");
     avformat_close_input(&context);
@@ -106,7 +108,6 @@ int bl_audio_decode(char const *const filename, struct
   index = 0;
 
   // Read the whole data and copy them into a huge buffer
-  av_init_packet(&avpkt);
   decoded_frame = av_frame_alloc();
   if (!decoded_frame) {
     fprintf(stderr, "Could not allocate audio frame\n");
@@ -230,7 +231,7 @@ int fill_song_properties(struct bl_song *const song, c
 #else
   song->sample_rate = codecpar->sample_rate;
   song->nb_bytes_per_sample = av_get_bytes_per_sample(codecpar->format);
-  song->channels = codecpar->channels;
+  song->channels = codecpar->ch_layout.nb_channels;
 #endif
   song->duration = (uint64_t)(context->duration) / ((uint64_t)AV_TIME_BASE);
   song->bitrate = context->bit_rate;
@@ -332,11 +333,21 @@ int fill_song_properties(struct bl_song *const song, c
                    codec_context->channel_layout, 0);
     av_opt_set_int(*swr_ctx, "out_sample_rate", SAMPLE_RATE, 0);
 #else
+#if LIBAVUTIL_VERSION_MAJOR < 58
     av_opt_set_int(*swr_ctx, "in_channel_layout", codecpar->channel_layout, 0);
     av_opt_set_int(*swr_ctx, "in_sample_rate", codecpar->sample_rate, 0);
     av_opt_set_sample_fmt(*swr_ctx, "in_sample_fmt", codecpar->format, 0);
     av_opt_set_int(*swr_ctx, "out_channel_layout", AV_CH_LAYOUT_STEREO, 0);
     av_opt_set_int(*swr_ctx, "out_sample_rate", SAMPLE_RATE, 0);
+#else
+    AVChannelLayout in_ch_layout = codecpar->ch_layout;
+    AVChannelLayout out_ch_layout = AV_CHANNEL_LAYOUT_STEREO;
+    av_opt_set_chlayout(*swr_ctx, "in_chlayout", &in_ch_layout, 0);
+    av_opt_set_int(*swr_ctx, "in_sample_rate", codecpar->sample_rate, 0);
+    av_opt_set_sample_fmt(*swr_ctx, "in_sample_fmt", codecpar->format, 0);
+    av_opt_set_chlayout(*swr_ctx, "out_chlayout", &out_ch_layout, 0);
+    av_opt_set_int(*swr_ctx, "out_sample_rate", SAMPLE_RATE, 0);
+#endif
 #endif
     av_opt_set_sample_fmt(*swr_ctx, "out_sample_fmt", AV_SAMPLE_FMT_S16, 0);
     if (swr_init(*swr_ctx) < 0) {
