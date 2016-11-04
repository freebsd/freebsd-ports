--- ffmpeg.c.orig	2015-07-13 10:00:56 UTC
+++ ffmpeg.c
@@ -39,7 +39,7 @@
 #include <libavformat/avio.h>
 #include <libswresample/swresample.h>
 #include <libavutil/opt.h>
-#include <libavutil/audioconvert.h>
+#include <libavutil/channel_layout.h>
 #ifndef AVUTIL_MATHEMATICS_H
 #include <libavutil/mathematics.h>
 #endif
@@ -347,7 +347,7 @@ static int ffmpeg_fill_buffer(AVFormatCo
 			      struct ffmpeg_output *output, SwrContext *swr)
 {
 #if (LIBAVCODEC_VERSION_INT >= ((53<<16) + (25<<8) + 0))
-	AVFrame *frame = avcodec_alloc_frame();
+	AVFrame *frame = av_frame_alloc();
 	int got_frame;
 #endif
 	while (1) {
@@ -363,7 +363,7 @@ static int ffmpeg_fill_buffer(AVFormatCo
 			if (av_read_frame(ic, &input->pkt) < 0) {
 				/* Force EOF once we can read no longer. */
 #if (LIBAVCODEC_VERSION_INT >= ((53<<16) + (25<<8) + 0))
-				avcodec_free_frame(&frame);
+				av_frame_free(&frame);
 #endif
 				return 0;
 			}
@@ -426,7 +426,7 @@ static int ffmpeg_fill_buffer(AVFormatCo
 				res = 0;
 			output->buffer_pos = output->buffer;
 			output->buffer_used_len = res * cc->channels * sizeof(int16_t);
-			avcodec_free_frame(&frame);
+			av_frame_free(&frame);
 			return output->buffer_used_len;
 		}
 #endif
@@ -566,7 +566,7 @@ static long ffmpeg_current_bitrate(struc
 	long bitrate = -1;
 #if (LIBAVFORMAT_VERSION_INT > ((51<<16)+(43<<8)+0))
 	/* ape codec returns silly numbers */
-	if (priv->codec->id == CODEC_ID_APE)
+	if (priv->codec->id == AV_CODEC_ID_APE)
 		return -1;
 #endif
 	if (priv->input->curr_duration > 0) {
