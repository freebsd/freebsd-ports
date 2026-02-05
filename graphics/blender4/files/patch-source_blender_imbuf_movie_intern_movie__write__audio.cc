--- source/blender/imbuf/movie/intern/movie_write_audio.cc.orig	2025-12-28 19:51:22 UTC
+++ source/blender/imbuf/movie/intern/movie_write_audio.cc
@@ -323,12 +323,12 @@ AVStream *alloc_audio_stream(MovieWriter *context,
   c->time_base.num = 1;
   c->time_base.den = c->sample_rate;
 
-  if (c->frame_size == 0) {
-    /* Used to be if ((c->codec_id >= CODEC_ID_PCM_S16LE) && (c->codec_id <= CODEC_ID_PCM_DVD))
-     * not sure if that is needed anymore, so let's try out if there are any
-     * complaints regarding some FFMPEG versions users might have. */
-    context->audio_input_samples = AV_INPUT_BUFFER_MIN_SIZE * 8 / c->bits_per_coded_sample /
-                                   audio_channels;
+  if (c->codec->capabilities & AV_CODEC_CAP_VARIABLE_FRAME_SIZE) {
+    /* If the audio format has a variable frame size, default to 1024.
+     * This is because we won't try to encode any variable frame size.
+     * 1024 seems to be a good compromize between size and speed.
+     */
+    context->audio_input_samples = 1024;
   }
   else {
     context->audio_input_samples = c->frame_size;
