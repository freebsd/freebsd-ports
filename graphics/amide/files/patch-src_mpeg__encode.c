--- src/mpeg_encode.c.orig	2014-01-23 20:13:52 UTC
+++ src/mpeg_encode.c
@@ -143,6 +143,7 @@ static void convert_rgb_pixbuf_to_yuv(yu
 
 #include <libavcodec/avcodec.h>
 
+#include <libavutil/frame.h>
 
 typedef struct {
   AVCodec *codec;
@@ -234,11 +235,11 @@ gpointer mpeg_encode_setup(gchar * outpu
 
   switch(type) {
   case ENCODE_MPEG4:
-    codec_type = CODEC_ID_MPEG4;
+    codec_type = AV_CODEC_ID_MPEG4;
     break;
   case ENCODE_MPEG1:
   default:
-    codec_type=CODEC_ID_MPEG1VIDEO;
+    codec_type=AV_CODEC_ID_MPEG1VIDEO;
     break;
   }
 
@@ -268,7 +269,7 @@ gpointer mpeg_encode_setup(gchar * outpu
     return NULL;
   }
 
-  encode->picture= avcodec_alloc_frame();
+  encode->picture= av_frame_alloc();
   if (!encode->picture) {
     g_warning("couldn't allocate memory for encode->picture");
     encode_free(encode);
@@ -293,11 +294,13 @@ gpointer mpeg_encode_setup(gchar * output_filename, mp
   encode->context->time_base= (AVRational){1,FRAMES_PER_SECOND};
   encode->context->gop_size = 10; /* emit one intra frame every ten frames */
   encode->context->max_b_frames=10;
-  encode->context->pix_fmt = PIX_FMT_YUV420P;
+  encode->context->pix_fmt = AV_PIX_FMT_YUV420P;
 
   /* encoding parameters */
   encode->context->sample_aspect_ratio= (AVRational){1,1}; /* our pixels are square */
+#if LIBAVCODEC_VERSION_MAJOR < 58
   encode->context->me_method=5; /* 5 is epzs */
+#endif
   encode->context->trellis=2; /* turn trellis quantization on */
 
   /* open it */
@@ -355,6 +356,10 @@ gpointer mpeg_encode_setup(gchar * outpu
   encode->picture->linesize[1] = encode->context->width/2;
   encode->picture->linesize[2] = encode->context->width/2;
 
+  encode->picture->width = xsize;
+  encode->picture->height = ysize;
+  encode->picture->format = AV_PIX_FMT_YUV420P;
+
   return (gpointer) encode;
 }
 
@@ -362,12 +367,21 @@ gpointer mpeg_encode_setup(gchar * outpu
 gboolean mpeg_encode_frame(gpointer data, GdkPixbuf * pixbuf) {
   encode_t * encode = data;
   gint out_size;
+  AVPacket packet = { 0 };
+  int ret, got_output = 0;
 
   convert_rgb_pixbuf_to_yuv(encode->yuv, pixbuf);
 
   /* encode the image */
-  out_size = avcodec_encode_video(encode->context, encode->output_buffer, encode->output_buffer_size, encode->picture);
-  fwrite(encode->output_buffer, 1, out_size, encode->output_file);
+  av_init_packet(&packet);
+  packet.data = encode->output_buffer;
+  packet.size = encode->output_buffer_size;
+  ret = avcodec_encode_video2(encode->context, &packet,
+			      encode->picture, &got_output);
+  if (ret < 0)
+      return FALSE;
+
+  fwrite(packet.data, 1, packet.size, encode->output_file);
 
   return TRUE;
 };
