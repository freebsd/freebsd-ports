https://github.com/visualboyadvance-m/visualboyadvance-m/commit/502de18
https://github.com/visualboyadvance-m/visualboyadvance-m/commit/a3a07d2
https://github.com/visualboyadvance-m/visualboyadvance-m/commit/029a5fc
https://github.com/visualboyadvance-m/visualboyadvance-m/commit/3f3c385
https://github.com/visualboyadvance-m/visualboyadvance-m/commit/f3f6ee7

--- src/common/ffmpeg.cpp.orig	2015-09-19 15:58:26 UTC
+++ src/common/ffmpeg.cpp
@@ -53,6 +53,26 @@ static void avformat_free_context(AVFormatContext *ctx)
 #endif
 }
 
+// For compatibility with 3.0+ ffmpeg
+#include <libavutil/version.h>
+#ifndef PixelFormat
+#define PixelFormat AVPixelFormat
+#endif
+#if LIBAVCODEC_VERSION_MAJOR > 56
+#define CODEC_ID_NONE AV_CODEC_ID_NONE
+#define CODEC_ID_PCM_S16LE AV_CODEC_ID_PCM_S16LE
+#define CODEC_ID_PCM_S16BE AV_CODEC_ID_PCM_S16BE
+#define CODEC_ID_PCM_U16LE AV_CODEC_ID_PCM_U16LE
+#define CODEC_ID_PCM_U16BE AV_CODEC_ID_PCM_U16BE
+#define CODEC_FLAG_GLOBAL_HEADER AV_CODEC_FLAG_GLOBAL_HEADER
+#endif
+#if LIBAVUTIL_VERSION_MAJOR > 54
+#define avcodec_alloc_frame av_frame_alloc
+#define PIX_FMT_RGB565LE AV_PIX_FMT_RGB565LE
+#define PIX_FMT_RGB24 AV_PIX_FMT_RGB24
+#define PIX_FMT_RGBA AV_PIX_FMT_RGBA
+#endif
+
 #define priv_AVFormatContext AVFormatContext
 #define priv_AVStream AVStream
 #define priv_AVOutputFormat AVOutputFormat
@@ -64,11 +84,22 @@ static void avformat_free_context(AVFormatContext *ctx)
 // I have no idea what size to make these buffers
 // I don't see any ffmpeg functions to guess the size, either
 
-// use frame size, or FF_MIN_BUFFER_SIZE (that seems to be what it wants)
+#ifdef AV_INPUT_BUFFER_MIN_SIZE
+
+    // use frame size, or AV_INPUT_BUFFER_MIN_SIZE (that seems to be what it wants)
+#define AUDIO_BUF_LEN (frame_len > AV_INPUT_BUFFER_MIN_SIZE ? frame_len : AV_INPUT_BUFFER_MIN_SIZE)
+    // use maximum frame size * 32 bpp * 2 for good measure
+#define VIDEO_BUF_LEN (AV_INPUT_BUFFER_MIN_SIZE + 256 * 244 * 4 * 2)
+
+#else
+
+    // use frame size, or FF_MIN_BUFFER_SIZE (that seems to be what it wants)
 #define AUDIO_BUF_LEN (frame_len > FF_MIN_BUFFER_SIZE ? frame_len : FF_MIN_BUFFER_SIZE)
-// use maximum frame size * 32 bpp * 2 for good measure
+    // use maximum frame size * 32 bpp * 2 for good measure
 #define VIDEO_BUF_LEN (FF_MIN_BUFFER_SIZE + 256 * 244 * 4 * 2)
 
+#endif
+
 bool MediaRecorder::did_init = false;
 
 MediaRecorder::MediaRecorder() : oc(0), vid_st(0), aud_st(0), video_buf(0),
@@ -103,10 +134,16 @@ MediaRet MediaRecorder::setup_sound_stream(const char *fname, AVOutputFormat *fm
 	oc = NULL;
 	return MRET_ERR_NOMEM;
     }
+
+    AVCodec *codec = avcodec_find_encoder(fmt->audio_codec);
+
     ctx = aud_st->codec;
     ctx->codec_id = fmt->audio_codec;
     ctx->codec_type = AVMEDIA_TYPE_AUDIO;
-    ctx->sample_fmt = AV_SAMPLE_FMT_S16;
+    // Some encoders don't like s16 (SAMPLE_FMT_S16)
+    ctx->sample_fmt = codec->sample_fmts[0];
+    // This was changed in the initial ffmpeg 3.0 update,
+    // but shouldn't (as far as I'm aware) cause problems with older versions
     ctx->bit_rate = 128000; // arbitrary; in case we're generating mp3
     ctx->sample_rate = soundGetSampleRate();
     ctx->channels = 2;
@@ -115,7 +152,6 @@ MediaRet MediaRecorder::setup_sound_stream(const char *fname, AVOutputFormat *fm
     if(fmt->flags & AVFMT_GLOBALHEADER)
 	ctx->flags |= CODEC_FLAG_GLOBAL_HEADER;
 
-    AVCodec *codec = avcodec_find_encoder(fmt->audio_codec);
 #if LIBAVCODEC_VERSION_INT < AV_VERSION_INT(53,6,0)
     if(!codec || avcodec_open(ctx, codec)) {
 #else
@@ -369,6 +405,7 @@ MediaRecorder::~MediaRecorder()
     Stop();
 }
 
+// Still needs updating for avcodec_encode_video2
 MediaRet MediaRecorder::AddFrame(const u8 *vid)
 {
     if(!oc || !vid_st)
@@ -376,6 +413,9 @@ MediaRet MediaRecorder::AddFrame(const u8 *vid)
 
     AVCodecContext *ctx = vid_st->codec;
     AVPacket pkt;
+#if LIBAVCODEC_VERSION_MAJOR > 56
+    int ret, got_packet = 0;
+#endif
 
     // strip borders.  inconsistent between depths for some reason
     // but fortunately consistent between gb/gba.
@@ -406,6 +446,7 @@ MediaRet MediaRecorder::AddFrame(const u8 *vid)
     }
     av_init_packet(&pkt);
     pkt.stream_index = vid_st->index;
+#ifdef AVFMT_RAWPICTURE
     if(oc->oformat->flags & AVFMT_RAWPICTURE) {
 	// this won't work due to border
 	// not sure what formats set this, anyway
@@ -413,7 +454,21 @@ MediaRet MediaRecorder::AddFrame(const u8 *vid)
 	pkt.data = f->data[0];
 	pkt.size = linesize * ctx->height;
     } else {
+#endif
+#if LIBAVCODEC_VERSION_MAJOR > 56
+        pkt.data = video_buf;
+        pkt.size = VIDEO_BUF_LEN;
+        f->format = ctx->pix_fmt;
+        f->width = ctx->width;
+        f->height = ctx->height;
+        ret = avcodec_encode_video2(ctx, &pkt, f, &got_packet);
+        if(!ret && got_packet && ctx->coded_frame) {
+            ctx->coded_frame->pts = pkt.pts;
+            ctx->coded_frame->key_frame = !!(pkt.flags & AV_PKT_FLAG_KEY);
+        }
+#else
 	pkt.size = avcodec_encode_video(ctx, video_buf, VIDEO_BUF_LEN, f);
+#endif
 	if(!pkt.size)
 	    return MRET_OK;
 	if(ctx->coded_frame && ctx->coded_frame->pts != AV_NOPTS_VALUE)
@@ -426,7 +481,9 @@ MediaRet MediaRecorder::AddFrame(const u8 *vid)
 	if(ctx->coded_frame->key_frame)
 	    pkt.flags |= AV_PKT_FLAG_KEY;
 	pkt.data = video_buf;
+#ifdef AVFMT_RAWPICTURE
     }
+#endif
     if(av_interleaved_write_frame(oc, &pkt) < 0) {
 	avformat_free_context(oc);
 	oc = NULL;
@@ -438,6 +495,53 @@ MediaRet MediaRecorder::AddFrame(const u8 *vid)
     return MRET_OK;
 }
 
+#if LIBAVCODEC_VERSION_MAJOR > 56
+/* FFmpeg depricated avcodec_encode_audio.
+ * It was removed completely in 3.0.
+ * This will at least get audio recording *working*
+ */
+static inline int MediaRecorderEncodeAudio(AVCodecContext *ctx,
+                                           AVPacket *pkt,
+                                           uint8_t *buf, int buf_size,
+                                           const short *samples)
+{
+    AVFrame *frame;
+    av_init_packet(pkt);
+    int ret, samples_size, got_packet = 0;
+
+    pkt->data = buf;
+    pkt->size = buf_size;
+    if (samples) {
+        frame = frame = av_frame_alloc();
+        if (ctx->frame_size) {
+            frame->nb_samples = ctx->frame_size;
+        } else {
+            frame->nb_samples = (int64_t)buf_size * 8 /
+                            (av_get_bits_per_sample(ctx->codec_id) *
+                            ctx->channels);
+        }
+        frame->format = ctx->sample_fmt;
+        frame->channel_layout = ctx->channel_layout;
+        samples_size = av_samples_get_buffer_size(NULL, ctx->channels,
+                        frame->nb_samples, ctx->sample_fmt, 1);
+        avcodec_fill_audio_frame(frame, ctx->channels, ctx->sample_fmt,
+                        (const uint8_t *)samples, samples_size, 1);
+        //frame->pts = AV_NOPTS_VALUE;
+    } else {
+        frame = NULL;
+    }
+        ret = avcodec_encode_audio2(ctx, pkt, frame, &got_packet);
+    if (!ret && got_packet && ctx->coded_frame) {
+        ctx->coded_frame->pts = pkt->pts;
+        ctx->coded_frame->key_frame = !!(pkt->flags & AV_PKT_FLAG_KEY);
+    }
+        if (frame && frame->extended_data != frame->data)
+        av_freep(&frame->extended_data);
+        return ret;
+
+}
+#endif
+
 MediaRet MediaRecorder::AddFrame(const u16 *aud)
 {
     if(!oc || !aud_st)
@@ -465,13 +569,19 @@ MediaRet MediaRecorder::AddFrame(const u16 *aud)
     }
     while(len + in_audio_buf2 >= frame_len) {
 	av_init_packet(&pkt);
+	#if LIBAVCODEC_VERSION_MAJOR > 56
+	MediaRecorderEncodeAudio(ctx, &pkt, audio_buf, frame_len,
+	#else
 	pkt.size = avcodec_encode_audio(ctx, audio_buf, frame_len,
+	#endif
 					(const short *)(in_audio_buf2 ? audio_buf2 : aud));
 	if(ctx->coded_frame && ctx->coded_frame->pts != AV_NOPTS_VALUE)
 	    pkt.pts = av_rescale_q(ctx->coded_frame->pts, ctx->time_base, aud_st->time_base);
 	pkt.flags |= AV_PKT_FLAG_KEY;
 	pkt.stream_index = aud_st->index;
+	#if LIBAVCODEC_VERSION_MAJOR < 57
 	pkt.data = audio_buf;
+	#endif
 	if(av_interleaved_write_frame(oc, &pkt) < 0) {
 	    avformat_free_context(oc);
 	    oc = NULL;
