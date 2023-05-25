--- source/blender/blenkernel/intern/writeffmpeg.c.orig	2023-05-25 22:43:31 UTC
+++ source/blender/blenkernel/intern/writeffmpeg.c
@@ -59,6 +59,7 @@
 #  include <libavutil/opt.h>
 #  include <libavutil/rational.h>
 #  include <libavutil/samplefmt.h>
+#  include <libavutil/channel_layout.h>
 #  include <libswscale/swscale.h>
 
 #  include "ffmpeg_compat.h"
@@ -574,7 +575,7 @@ static AVStream *alloc_video_stream(FFMpegContext *con
                                     int error_size)
 {
   AVStream *st;
-  AVCodec *codec;
+  const AVCodec *codec;
   AVDictionary *opts = NULL;
 
   error[0] = '\0';
@@ -601,7 +602,7 @@ static AVStream *alloc_video_stream(FFMpegContext *con
   }
 
   /* Load codec defaults into 'c'. */
-  avcodec_get_context_defaults3(c, codec);
+  //avcodec_get_context_defaults3(c, codec);
 
   /* Get some values from the current render settings */
 
@@ -814,7 +815,7 @@ static AVStream *alloc_audio_stream(FFMpegContext *con
                                     int error_size)
 {
   AVStream *st;
-  AVCodec *codec;
+  const AVCodec *codec;
   AVDictionary *opts = NULL;
 
   error[0] = '\0';
@@ -842,7 +843,7 @@ static AVStream *alloc_audio_stream(FFMpegContext *con
   }
 
   /* Load codec defaults into 'c'. */
-  avcodec_get_context_defaults3(c, codec);
+  //avcodec_get_context_defaults3(c, codec);
 
   c->sample_rate = rd->ffcodecdata.audio_mixrate;
   c->bit_rate = context->ffmpeg_audio_bitrate * 1000;
@@ -1038,7 +1039,7 @@ static int start_ffmpeg_impl(FFMpegContext *context,
     BKE_report(reports, RPT_ERROR, "No valid formats found");
     return 0;
   }
-  fmt = av_guess_format(NULL, exts[0], NULL);
+  fmt = (AVOutputFormat*)(av_guess_format(NULL, exts[0], NULL));
   if (!fmt) {
     BKE_report(reports, RPT_ERROR, "No valid formats found");
     return 0;
@@ -1554,7 +1555,7 @@ static IDProperty *BKE_ffmpeg_property_add(RenderData 
                                            const AVOption *o,
                                            const AVOption *parent)
 {
-  AVCodecContext c;
+  //AVCodecContext c;
   IDProperty *group;
   IDProperty *prop;
   IDPropertyTemplate val;
@@ -1563,7 +1564,7 @@ static IDProperty *BKE_ffmpeg_property_add(RenderData 
 
   val.i = 0;
 
-  avcodec_get_context_defaults3(&c, NULL);
+  //avcodec_get_context_defaults3(&c, NULL);
 
   if (!rd->ffcodecdata.properties) {
     rd->ffcodecdata.properties = IDP_New(IDP_GROUP, &val, "ffmpeg");
@@ -1632,7 +1633,7 @@ int BKE_ffmpeg_property_add_string(RenderData *rd, con
   char *param;
   IDProperty *prop = NULL;
 
-  avcodec_get_context_defaults3(&c, NULL);
+  //avcodec_get_context_defaults3(&c, NULL);
 
   BLI_strncpy(name_, str, sizeof(name_));
 
