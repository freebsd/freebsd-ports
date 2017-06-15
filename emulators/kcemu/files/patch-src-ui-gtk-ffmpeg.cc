--- src/ui/gtk/ffmpeg.cc.orig	2010-03-07 19:50:23 UTC
+++ src/ui/gtk/ffmpeg.cc
@@ -48,7 +48,7 @@ FfmpegVideoEncoder::init(const char *fil
 
   av_register_all();
 
-  AVOutputFormat *fmt = guess_format("avi", NULL, "video/x-msvideo");
+  AVOutputFormat *fmt = av_guess_format("avi", NULL, "video/x-msvideo");
   if (fmt == NULL)
     return false;
 
@@ -59,14 +59,15 @@ FfmpegVideoEncoder::init(const char *fil
   _context->oformat = fmt;
   snprintf(_context->filename, sizeof (_context->filename), "%s", filename);
 
-  _stream = av_new_stream(_context, 0);
+  _stream = avformat_new_stream(_context, NULL);
   if (_stream == NULL)
     {
       close();
       return false;
     }
+  _stream->id = 0;
   _stream->codec->codec_id = fmt->video_codec;
-  _stream->codec->codec_type = CODEC_TYPE_VIDEO;
+  _stream->codec->codec_type = AVMEDIA_TYPE_VIDEO;
   _stream->codec->codec_tag = MKTAG('D', 'X', '5', '0');
 
   _stream->codec->bit_rate = 79000 + 1000 * pow(1.4, quality * 20.0);
@@ -75,20 +76,14 @@ FfmpegVideoEncoder::init(const char *fil
   _stream->codec->time_base.den = 50;
   _stream->codec->time_base.num = fps_den;
   _stream->codec->gop_size = 100 / fps_den;
-  _stream->codec->pix_fmt = PIX_FMT_YUV420P;
+  _stream->codec->pix_fmt = AV_PIX_FMT_YUV420P;
 
   // some formats want stream headers to be separate
   if (_context->oformat->flags & AVFMT_GLOBALHEADER)
     _stream->codec->flags |= CODEC_FLAG_GLOBAL_HEADER;
 
-  if (av_set_parameters(_context, NULL) < 0)
-    {
-      close();
-      return false;
-    }
-
   AVCodec *codec = avcodec_find_encoder(_stream->codec->codec_id);
-  if (avcodec_open(_stream->codec, codec) < 0)
+  if (avcodec_open2(_stream->codec, codec, NULL) < 0)
     {
       close();
       return false;
@@ -102,7 +97,7 @@ FfmpegVideoEncoder::init(const char *fil
       return false;
     }
 
-  _frame = avcodec_alloc_frame();
+  _frame = av_frame_alloc();
   if (_frame == NULL)
     {
       close();
@@ -119,14 +114,14 @@ FfmpegVideoEncoder::init(const char *fil
 
   avpicture_fill((AVPicture *) _frame, buf, _stream->codec->pix_fmt, width, height);
 
-  if (url_fopen(&_context->pb, filename, URL_WRONLY) < 0)
+  if (avio_open(&_context->pb, filename, AVIO_FLAG_WRITE) < 0)
     {
       close();
       return false;
     }
 
   //dump_format(_context, 0, filename, 1);
-  av_write_header(_context);
+  avformat_write_header(_context, NULL);
   return true;
 }
 
@@ -161,20 +156,21 @@ FfmpegVideoEncoder::encode(byte_t *image
         }
     }
 
-  int out_size = avcodec_encode_video(_stream->codec, _buf, _bufsize, _frame);
-  if (out_size == 0)
-    return true;
-
   AVPacket pkt;
   av_init_packet(&pkt);
+  pkt.data = _buf;
+  pkt.size = _bufsize;
+
+  int got_packet = 0;
+  int ret = avcodec_encode_video2(_stream->codec, &pkt, _frame, &got_packet);
+  if (ret < 0 || !got_packet || pkt.size <= 0)
+    return true;
 
   if (_stream->codec->coded_frame->pts != AV_NOPTS_VALUE)
     pkt.pts = av_rescale_q(_stream->codec->coded_frame->pts, _stream->codec->time_base, _stream->time_base);
   if (_stream->codec->coded_frame->key_frame)
-    pkt.flags |= PKT_FLAG_KEY;
+    pkt.flags |= AV_PKT_FLAG_KEY;
   pkt.stream_index = _stream->index;
-  pkt.data = _buf;
-  pkt.size = out_size;
 
   return av_interleaved_write_frame(_context, &pkt) == 0;
 }
@@ -197,7 +193,7 @@ FfmpegVideoEncoder::close(void)
       av_freep(&_context->streams[i]->codec);
       av_freep(&_context->streams[i]);
     }
-  url_fclose(_context->pb);
+  avio_close(_context->pb);
   
   av_free(_context);
   
@@ -207,4 +203,4 @@ FfmpegVideoEncoder::close(void)
   _buf = NULL;
 }
 
-#endif /* HAVE_LIBAVFORMAT */
\ No newline at end of file
+#endif /* HAVE_LIBAVFORMAT */
