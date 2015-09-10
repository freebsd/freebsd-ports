--- src/ui/gtk/ffmpeg.cc.orig	2010-03-07 20:50:23.000000000 +0100
+++ src/ui/gtk/ffmpeg.cc	2015-07-03 22:59:12.842256554 +0200
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
@@ -81,14 +82,8 @@ FfmpegVideoEncoder::init(const char *fil
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
 
@@ -171,7 +166,7 @@ FfmpegVideoEncoder::encode(byte_t *image
   if (_stream->codec->coded_frame->pts != AV_NOPTS_VALUE)
     pkt.pts = av_rescale_q(_stream->codec->coded_frame->pts, _stream->codec->time_base, _stream->time_base);
   if (_stream->codec->coded_frame->key_frame)
-    pkt.flags |= PKT_FLAG_KEY;
+    pkt.flags |= AV_PKT_FLAG_KEY;
   pkt.stream_index = _stream->index;
   pkt.data = _buf;
   pkt.size = out_size;
@@ -197,7 +192,7 @@ FfmpegVideoEncoder::close(void)
       av_freep(&_context->streams[i]->codec);
       av_freep(&_context->streams[i]);
     }
-  url_fclose(_context->pb);
+  avio_close(_context->pb);
   
   av_free(_context);
   
@@ -207,4 +202,4 @@ FfmpegVideoEncoder::close(void)
   _buf = NULL;
 }
 
-#endif /* HAVE_LIBAVFORMAT */
\ No newline at end of file
+#endif /* HAVE_LIBAVFORMAT */
