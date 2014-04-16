--- src/gfxoutputdrv/ffmpeglib.h.orig	2011-10-24 21:06:48.000000000 +0200
+++ src/gfxoutputdrv/ffmpeglib.h	2012-11-25 13:09:18.518868503 +0100
@@ -70,7 +70,7 @@
 /* avcodec fucntions */
 typedef int (*avcodec_open_t) (AVCodecContext*, AVCodec*);
 typedef int (*avcodec_close_t) (AVCodecContext*);
-typedef AVCodec* (*avcodec_find_encoder_t) (enum CodecID);
+typedef AVCodec* (*avcodec_find_encoder_t) (enum AVCodecID);
 typedef int (*avcodec_encode_audio_t) (AVCodecContext*, uint8_t*, int, const short*);
 typedef int (*avcodec_encode_video_t) (AVCodecContext*, uint8_t*, int, const AVFrame*);
 typedef int (*avpicture_fill_t) (AVPicture*, uint8_t*, int, int, int);
@@ -80,12 +80,11 @@ typedef int (*avpicture_get_size_t) (int
 typedef void (*av_init_packet_t) (AVPacket *pkt);
 typedef void (*av_register_all_t) (void);
 typedef AVStream* (*av_new_stream_t) (AVFormatContext*, int);
-typedef int (*av_set_parameters_t) (AVFormatContext*, AVFormatParameters*);
-typedef int (*av_write_header_t) (AVFormatContext*);
+typedef int (*avformat_write_header_t) (AVFormatContext*, AVDictionary **);
 typedef int (*av_write_frame_t) (AVFormatContext*, AVPacket*);
 typedef int (*av_write_trailer_t) (AVFormatContext*);
-typedef int (*url_fopen_t) (ByteIOContext**, const char*, int);
-typedef int (*url_fclose_t) (ByteIOContext*);
+typedef int (*avio_open_t) (AVIOContext**, const char*, int);
+typedef int (*avio_close_t) (AVIOContext*);
 typedef void (*dump_format_t) (AVFormatContext *, int, const char*, int);
 typedef AVOutputFormat* (*av_guess_format_t) (const char*, const char*, const char*);
 typedef int (*img_convert_t) (AVPicture*, int, AVPicture*, int, int, int);
@@ -118,12 +117,11 @@ struct ffmpeglib_s {
     av_init_packet_t            p_av_init_packet;
     av_register_all_t           p_av_register_all;
     av_new_stream_t             p_av_new_stream;
-    av_set_parameters_t         p_av_set_parameters;
-    av_write_header_t           p_av_write_header;
+    avformat_write_header_t     p_avformat_write_header;
     av_write_frame_t            p_av_write_frame;
     av_write_trailer_t          p_av_write_trailer;
-    url_fopen_t                 p_url_fopen;
-    url_fclose_t                p_url_fclose;
+    avio_open_t                 p_avio_open;
+    avio_close_t                p_avio_close;
     dump_format_t               p_dump_format;
     av_guess_format_t           p_av_guess_format;
 #ifndef HAVE_FFMPEG_SWSCALE
