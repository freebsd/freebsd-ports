--- src/osgPlugins/ffmpeg/FFmpegDecoder.cpp.orig	2022-12-01 18:17:31 UTC
+++ src/osgPlugins/ffmpeg/FFmpegDecoder.cpp
@@ -1,4 +1,3 @@
-
 #include "FFmpegDecoder.hpp"
 #include "FFmpegParameters.hpp"
 
@@ -36,8 +35,10 @@ FFmpegDecoder::FFmpegDecoder() :
 }
 
 FFmpegDecoder::FFmpegDecoder() :
-    m_audio_stream(0),
-    m_video_stream(0),
+    m_audio_stream(nullptr),
+    m_video_stream(nullptr),
+    m_audio_index(-1),
+    m_video_index(-1),
     m_audio_queue(100),
     m_video_queue(100),
     m_audio_decoder(m_audio_queue, m_clocks),
@@ -61,10 +62,10 @@ bool FFmpegDecoder::open(const std::string & filename,
     try
     {
         // Open video file
-        AVFormatContext * p_format_context = 0;
-        AVInputFormat *iformat = 0;
+        AVFormatContext * p_format_context = nullptr;
+        AVInputFormat *iformat = nullptr;
 
-        if (filename.compare(0, 5, "/dev/")==0)
+        if (filename.compare(0, 5, "/dev/") == 0)
         {
 #ifdef ANDROID
             throw std::runtime_error("Device not supported on Android");
@@ -78,24 +79,24 @@ bool FFmpegDecoder::open(const std::string & filename,
             }
 
             std::string format = "video4linux2";
-            iformat = av_find_input_format(format.c_str());
+            iformat = const_cast<AVInputFormat*>(av_find_input_format(format.c_str()));
 
             if (iformat)
             {
-                OSG_INFO<<"Found input format: "<<format<<std::endl;
+                OSG_INFO << "Found input format: " << format << std::endl;
             }
             else
             {
-                OSG_INFO<<"Failed to find input format: "<<format<<std::endl;
+                OSG_INFO << "Failed to find input format: " << format << std::endl;
             }
 
 #endif
         }
         else
         {
-            iformat = parameters ? parameters->getFormat() : 0;
-            AVIOContext* context = parameters ? parameters->getContext() : 0;
-            if (context != NULL)
+            iformat = parameters ? const_cast<AVInputFormat*>(parameters->getFormat()) : nullptr;
+            AVIOContext* context = parameters ? parameters->getContext() : nullptr;
+            if (context != nullptr)
             {
                 p_format_context = avformat_alloc_context();
                 p_format_context->pb = context;
@@ -105,22 +106,7 @@ bool FFmpegDecoder::open(const std::string & filename,
         int error = avformat_open_input(&p_format_context, filename.c_str(), iformat, parameters->getOptions());
         if (error != 0)
         {
-            std::string error_str;
-            switch (error)
-            {
-                //case AVERROR_UNKNOWN: error_str = "AVERROR_UNKNOWN"; break;   // same value as AVERROR_INVALIDDATA
-                case AVERROR_IO: error_str = "AVERROR_IO"; break;
-                case AVERROR_NUMEXPECTED: error_str = "AVERROR_NUMEXPECTED"; break;
-                case AVERROR_INVALIDDATA: error_str = "AVERROR_INVALIDDATA"; break;
-                case AVERROR_NOMEM: error_str = "AVERROR_NOMEM"; break;
-                case AVERROR_NOFMT: error_str = "AVERROR_NOFMT"; break;
-                case AVERROR_NOTSUPP: error_str = "AVERROR_NOTSUPP"; break;
-                case AVERROR_NOENT: error_str = "AVERROR_NOENT"; break;
-                case AVERROR_PATCHWELCOME: error_str = "AVERROR_PATCHWELCOME"; break;
-                default: error_str = "Unknown error"; break;
-            }
-
-            throw std::runtime_error("av_open_input_file() failed : " + error_str);
+            throw std::runtime_error("avformat_open_input() failed: " + AvStrError(error));
         }
 
         m_format_context.reset(p_format_context);
@@ -128,15 +114,15 @@ bool FFmpegDecoder::open(const std::string & filename,
         // Retrieve stream info
         // Only buffer up to one and a half seconds by default
         float max_analyze_duration = 1.5;
-        AVDictionaryEntry *mad = av_dict_get( *parameters->getOptions(), "mad", NULL, 0 );
-        if ( mad ) {
+        AVDictionaryEntry *mad = av_dict_get(*parameters->getOptions(), "mad", NULL, 0);
+        if (mad) {
             max_analyze_duration = atof(mad->value);
         }
         p_format_context->max_analyze_duration = AV_TIME_BASE * max_analyze_duration;
 //        p_format_context->probesize = 100000;
 
         if (avformat_find_stream_info(p_format_context, NULL) < 0)
-            throw std::runtime_error("av_find_stream_info() failed");
+            throw std::runtime_error("avformat_find_stream_info() failed");
 
         m_duration = double(m_format_context->duration) / AV_TIME_BASE;
         if (m_format_context->start_time != static_cast<int64_t>(AV_NOPTS_VALUE))
@@ -159,7 +145,7 @@ bool FFmpegDecoder::open(const std::string & filename,
             m_audio_stream = m_format_context->streams[m_audio_index];
         else
         {
-            m_audio_stream = 0;
+            m_audio_stream = nullptr;
             m_audio_index = std::numeric_limits<unsigned int>::max();
         }
 
@@ -271,7 +257,7 @@ bool FFmpegDecoder::readNextPacketNormal()
 {
     AVPacket packet;
 
-    if (! m_pending_packet)
+    if (!m_pending_packet)
     {
         bool end_of_stream = false;
 
@@ -279,10 +265,10 @@ bool FFmpegDecoder::readNextPacketNormal()
         int error = av_read_frame(m_format_context.get(), &packet);
         if (error < 0)
         {
-            if (error == static_cast<int>(AVERROR_EOF) ||
-                m_format_context.get()->pb->eof_reached)
+            if (error == static_cast<int>(AVERROR_EOF) || m_format_context.get()->pb->eof_reached)
                 end_of_stream = true;
-            else {
+            else
+            {
                 OSG_FATAL << "av_read_frame() returned " << AvStrError(error) << std::endl;
                 throw std::runtime_error("av_read_frame() failed");
             }
@@ -303,12 +289,6 @@ bool FFmpegDecoder::readNextPacketNormal()
         }
         else
         {
-            // Make the packet data available beyond av_read_frame() logical scope.
-            if ((error = av_dup_packet(&packet)) < 0) {
-                OSG_FATAL << "av_dup_packet() returned " << AvStrError(error) << std::endl;
-                throw std::runtime_error("av_dup_packet() failed");
-            }
-
             m_pending_packet = FFmpegPacket(packet);
         }
     }
@@ -340,8 +320,6 @@ bool FFmpegDecoder::readNextPacketNormal()
     return false;
 }
 
-
-
 bool FFmpegDecoder::readNextPacketEndOfStream()
 {
     const FFmpegPacket packet(FFmpegPacket::PACKET_END_OF_STREAM);
@@ -352,8 +330,6 @@ bool FFmpegDecoder::readNextPacketEndOfStream()
     return false;
 }
 
-
-
 bool FFmpegDecoder::readNextPacketRewinding()
 {
     const FFmpegPacket packet(FFmpegPacket::PACKET_FLUSH);
@@ -364,8 +340,6 @@ bool FFmpegDecoder::readNextPacketRewinding()
     return false;
 }
 
-
-
 void FFmpegDecoder::rewindButDontFlushQueues()
 {
     const AVRational AvTimeBaseQ = { 1, AV_TIME_BASE }; // = AV_TIME_BASE_Q
@@ -374,7 +348,8 @@ void FFmpegDecoder::rewindButDontFlushQueues()
     const int64_t seek_target = av_rescale_q(pos, AvTimeBaseQ, m_video_stream->time_base);
 
     int error = 0;
-    if ((error = av_seek_frame(m_format_context.get(), m_video_index, seek_target, 0/*AVSEEK_FLAG_BYTE |*/ /*AVSEEK_FLAG_BACKWARD*/)) < 0) {
+    if ((error = av_seek_frame(m_format_context.get(), m_video_index, seek_target, 0)) < 0)
+    {
         OSG_FATAL << "av_seek_frame returned " << AvStrError(error) << std::endl;
         throw std::runtime_error("av_seek_frame failed()");
     }
@@ -397,13 +372,14 @@ void FFmpegDecoder::seekButDontFlushQueues(double time
 {
     const AVRational AvTimeBaseQ = { 1, AV_TIME_BASE }; // = AV_TIME_BASE_Q
 
-    const int64_t pos = int64_t(m_clocks.getStartTime()+time * double(AV_TIME_BASE));
+    const int64_t pos = int64_t(m_clocks.getStartTime() + time * double(AV_TIME_BASE));
     const int64_t seek_target = av_rescale_q(pos, AvTimeBaseQ, m_video_stream->time_base);
 
     m_clocks.setSeekTime(time);
 
     int error = 0;
-    if ((error = av_seek_frame(m_format_context.get(), m_video_index, seek_target, 0/*AVSEEK_FLAG_BYTE |*/ /*AVSEEK_FLAG_BACKWARD*/)) < 0) {
+    if ((error = av_seek_frame(m_format_context.get(), m_video_index, seek_target, 0)) < 0)
+    {
         OSG_FATAL << "av_seek_frame() returned " << AvStrError(error) << std::endl;
         throw std::runtime_error("av_seek_frame failed()");
     }
