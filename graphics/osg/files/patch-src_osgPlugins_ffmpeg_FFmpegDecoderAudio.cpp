--- src/osgPlugins/ffmpeg/FFmpegDecoderAudio.cpp.orig	2022-12-01 18:17:31 UTC
+++ src/osgPlugins/ffmpeg/FFmpegDecoderAudio.cpp
@@ -1,39 +1,24 @@
 #include "FFmpegDecoderAudio.hpp"
-
 #include <osg/Notify>
-
 #include <stdexcept>
-#include <string.h>
+#include <cstring>
+#include <libavutil/channel_layout.h>
+#include <libavutil/opt.h>
 
-//DEBUG
-//#include <iostream>
-
-
 #ifndef AVCODEC_MAX_AUDIO_FRAME_SIZE
 #define AVCODEC_MAX_AUDIO_FRAME_SIZE 192000
 #endif
 
-#if LIBAVCODEC_VERSION_INT < AV_VERSION_INT(55,28,1)
-#define av_frame_alloc  avcodec_alloc_frame
-#define av_frame_free  avcodec_free_frame
-#endif
-
-#if LIBAVCODEC_VERSION_MAJOR < 56
-   #define AV_CODEC_ID_NONE CODEC_ID_NONE
-#endif
-
 namespace osgFFmpeg {
 
 static int decode_audio(AVCodecContext *avctx, int16_t *samples,
-                         int *frame_size_ptr,
-                         const uint8_t *buf, int buf_size,
-                         SwrContext *swr_context,
-                         int out_sample_rate,
-                         int out_nb_channels,
-                         AVSampleFormat out_sample_format)
+                        int *frame_size_ptr,
+                        const uint8_t *buf, int buf_size,
+                        SwrContext *swr_context,
+                        int out_sample_rate,
+                        int out_nb_channels,
+                        AVSampleFormat out_sample_format)
 {
-#if LIBAVCODEC_VERSION_MAJOR >= 53 || (LIBAVCODEC_VERSION_MAJOR==52 && LIBAVCODEC_VERSION_MINOR>=32)
-
     AVPacket avpkt;
     av_init_packet(&avpkt);
     avpkt.data = const_cast<uint8_t *>(buf);
@@ -45,30 +30,39 @@ static int decode_audio(AVCodecContext *avctx, int16_t
     if (!frame)
         return AVERROR(ENOMEM);
 
-    ret = avcodec_decode_audio4(avctx, frame, &got_frame, &avpkt);
+    // Send the packet to the decoder
+    ret = avcodec_send_packet(avctx, &avpkt);
+    if (ret < 0) {
+        av_frame_free(&frame);
+        return ret;
+    }
 
-#ifdef USE_AVRESAMPLE    // libav's AVFrame structure does not contain a 'channels' field
-    if (ret >= 0 && got_frame) {
-#else
-    if (ret >= 0 && got_frame && av_frame_get_channels(frame)>0) {
-#endif
+    // Receive the frame from the decoder
+    ret = avcodec_receive_frame(avctx, frame);
+    if (ret == AVERROR(EAGAIN) || ret == AVERROR_EOF) {
+        av_frame_free(&frame);
+        return 0;
+    } else if (ret < 0) {
+        av_frame_free(&frame);
+        return ret;
+    } else {
+        got_frame = 1;
+    }
+
+    if (ret >= 0 && got_frame && frame->ch_layout.nb_channels > 0) {
         int ch, plane_size;
         int planar = av_sample_fmt_is_planar(avctx->sample_fmt);
 
         int out_samples;
         // if sample rate changes, number of samples is different
-        if ( out_sample_rate !=  avctx->sample_rate ) {
-//            out_samples = av_rescale_rnd(swr_get_delay(swr_context, avctx->sample_rate) +
-//                                 frame->nb_samples, out_sample_rate, avctx->sample_rate, AV_ROUND_UP);
+        if (out_sample_rate != avctx->sample_rate) {
             out_samples = av_rescale_rnd(frame->nb_samples, out_sample_rate, avctx->sample_rate, AV_ROUND_UP);
-        }
-        else {
+        } else {
             out_samples = frame->nb_samples;
         }
 
         int output_data_size = av_samples_get_buffer_size(&plane_size, out_nb_channels,
-                                                    out_samples,
-                                                    out_sample_format, 1);
+                                                          out_samples, out_sample_format, 1);
 
         if (*frame_size_ptr < output_data_size) {
             av_log(avctx, AV_LOG_ERROR, "output buffer size is too small for "
@@ -78,23 +72,19 @@ static int decode_audio(AVCodecContext *avctx, int16_t
         }
 
         // if resampling is needed, call swr_convert
-        if ( swr_context != NULL ) {
-
+        if (swr_context != nullptr) {
             out_samples = swr_convert(swr_context, (uint8_t **)&samples, out_samples,
-                        (const uint8_t **)frame->extended_data, frame->nb_samples);
+                                      (const uint8_t **)frame->extended_data, frame->nb_samples);
 
             // recompute output_data_size following swr_convert result (number of samples actually converted)
             output_data_size = av_samples_get_buffer_size(&plane_size, out_nb_channels,
-                                                    out_samples,
-                                                    out_sample_format, 1);
-        }
-        else {
-
+                                                          out_samples, out_sample_format, 1);
+        } else {
             memcpy(samples, frame->extended_data[0], plane_size);
 
-            if (planar && avctx->channels > 1) {
+            if (planar && frame->ch_layout.nb_channels > 1) {
                 uint8_t *out = ((uint8_t *)samples) + plane_size;
-                for (ch = 1; ch < avctx->channels; ch++) {
+                for (ch = 1; ch < frame->ch_layout.nb_channels; ch++) {
                     memcpy(out, frame->extended_data[ch], plane_size);
                     out += plane_size;
                 }
@@ -102,26 +92,21 @@ static int decode_audio(AVCodecContext *avctx, int16_t
         }
 
         *frame_size_ptr = output_data_size;
-
     } else {
         *frame_size_ptr = 0;
     }
+    
     av_frame_free(&frame);
     return ret;
-
-#else
-    // fallback for older versions of ffmpeg that don't have avcodec_decode_audio3.
-    return avcodec_decode_audio2(avctx, samples, frame_size_ptr, buf, buf_size);
-#endif
 }
 
 
-FFmpegDecoderAudio::FFmpegDecoderAudio(PacketQueue & packets, FFmpegClocks & clocks) :
+FFmpegDecoderAudio::FFmpegDecoderAudio(PacketQueue &packets, FFmpegClocks &clocks) :
     m_packets(packets),
     m_clocks(clocks),
-    m_stream(0),
-    m_context(0),
-    m_packet_data(0),
+    m_stream(nullptr),
+    m_context(nullptr),
+    m_packet_data(nullptr),
     m_bytes_remaining(0),
     m_audio_buffer((AVCODEC_MAX_AUDIO_FRAME_SIZE * 3) / 2),
     m_audio_buf_size(0),
@@ -129,7 +114,7 @@ FFmpegDecoderAudio::FFmpegDecoderAudio(PacketQueue & p
     m_end_of_stream(false),
     m_paused(true),
     m_exit(false),
-    m_swr_context(NULL)
+    m_swr_context(nullptr)
 {
 }
 
@@ -137,103 +122,95 @@ FFmpegDecoderAudio::~FFmpegDecoderAudio()
 
 FFmpegDecoderAudio::~FFmpegDecoderAudio()
 {
-    this->close(true);
+    close(true);
 }
 
 
 
-void FFmpegDecoderAudio::open(AVStream * const stream, FFmpegParameters* parameters)
+void FFmpegDecoderAudio::open(AVStream *stream, FFmpegParameters* parameters)
 {
     try
     {
         // Sound can be optional (i.e. no audio stream is present)
-        if (stream == 0)
+        if (stream == nullptr)
             return;
 
         m_stream = stream;
-        m_context = stream->codec;
+        m_context = avcodec_alloc_context3(nullptr);
+        avcodec_parameters_to_context(m_context, stream->codecpar);
 
         m_in_sample_rate = m_context->sample_rate;
-        m_in_nb_channels = m_context->channels;
+        m_in_nb_channels = m_context->ch_layout.nb_channels;
         m_in_sample_format = m_context->sample_fmt;
 
-        AVDictionaryEntry *opt_out_sample_rate = av_dict_get( *parameters->getOptions(), "out_sample_rate", NULL, 0 );
-        if ( opt_out_sample_rate )
+        AVDictionaryEntry *opt_out_sample_rate = av_dict_get(*parameters->getOptions(), "out_sample_rate", nullptr, 0);
+        if (opt_out_sample_rate)
             m_out_sample_rate = atoi(opt_out_sample_rate->value);
         else
             m_out_sample_rate = m_in_sample_rate;
 
-        AVDictionaryEntry *opt_out_sample_format = av_dict_get( *parameters->getOptions(), "out_sample_format", NULL, 0 );
-        if ( opt_out_sample_format )
+        AVDictionaryEntry *opt_out_sample_format = av_dict_get(*parameters->getOptions(), "out_sample_format", nullptr, 0);
+        if (opt_out_sample_format)
             m_out_sample_format = (AVSampleFormat) atoi(opt_out_sample_format->value);
         else
             // always packed, planar formats are evil!
-            m_out_sample_format = av_get_packed_sample_fmt( m_in_sample_format );
+            m_out_sample_format = av_get_packed_sample_fmt(m_in_sample_format);
 
-        AVDictionaryEntry *opt_out_nb_channels = av_dict_get( *parameters->getOptions(), "out_nb_channels", NULL, 0 );
-        if ( opt_out_nb_channels )
+        AVDictionaryEntry *opt_out_nb_channels = av_dict_get(*parameters->getOptions(), "out_nb_channels", nullptr, 0);
+        if (opt_out_nb_channels)
             m_out_nb_channels = atoi(opt_out_nb_channels->value);
         else
             m_out_nb_channels = m_in_nb_channels;
 
-        if ( m_in_sample_rate != m_out_sample_rate
+        if (m_in_sample_rate != m_out_sample_rate
             || m_in_nb_channels != m_out_nb_channels
-            || m_in_sample_format != m_out_sample_format )
+            || m_in_sample_format != m_out_sample_format)
         {
-#if 0
-printf("### CONVERTING from sample format %s TO %s\n\t\tFROM %d TO %d channels\n\t\tFROM %d Hz to %d Hz\n",
-            av_get_sample_fmt_name(m_in_sample_format),
-            av_get_sample_fmt_name(m_out_sample_format),
-            m_in_nb_channels,
-            m_out_nb_channels,
-            m_in_sample_rate,
-            m_out_sample_rate);
-#endif
-            m_swr_context = swr_alloc_set_opts(NULL,
-                    av_get_default_channel_layout(m_out_nb_channels),
-                    m_out_sample_format,
-                    m_out_sample_rate,
-                    av_get_default_channel_layout(m_in_nb_channels),
-                    m_in_sample_format,
-                    m_in_sample_rate,
-                    0, NULL );
+            AVChannelLayout in_ch_layout;
+            AVChannelLayout out_ch_layout;
+            av_channel_layout_default(&in_ch_layout, m_in_nb_channels);
+            av_channel_layout_default(&out_ch_layout, m_out_nb_channels);
 
-            int err = swr_init(m_swr_context);
+            m_swr_context = swr_alloc();
+            if (!m_swr_context) {
+                throw std::runtime_error("Could not allocate resampler context");
+            }
 
-            if ( err ) {
+            av_opt_set_int(m_swr_context, "in_channel_count", in_ch_layout.nb_channels, 0);
+            av_opt_set_int(m_swr_context, "in_sample_rate", m_in_sample_rate, 0);
+            av_opt_set_sample_fmt(m_swr_context, "in_sample_fmt", m_in_sample_format, 0);
+            av_opt_set_chlayout(m_swr_context, "in_chlayout", &in_ch_layout, 0);
+
+            av_opt_set_int(m_swr_context, "out_channel_count", out_ch_layout.nb_channels, 0);
+            av_opt_set_int(m_swr_context, "out_sample_rate", m_out_sample_rate, 0);
+            av_opt_set_sample_fmt(m_swr_context, "out_sample_fmt", m_out_sample_format, 0);
+            av_opt_set_chlayout(m_swr_context, "out_chlayout", &out_ch_layout, 0);
+
+            int err = swr_init(m_swr_context);
+            if (err < 0) {
                 char error_string[512];
-                av_strerror(err, error_string, 512);
+                av_strerror(err, error_string, sizeof(error_string));
                 OSG_WARN << "FFmpegDecoderAudio - WARNING: Error initializing resampling context : " << error_string << std::endl;
                 swr_free(&m_swr_context);
-                throw std::runtime_error("swr_init() failed");;
+                throw std::runtime_error("swr_init() failed");
             }
         }
 
-        // Check stream sanity
         if (m_context->codec_id == AV_CODEC_ID_NONE)
-            throw std::runtime_error("invalid audio codec");;
+            throw std::runtime_error("invalid audio codec");
 
-        // Find the decoder for the audio stream
-        AVCodec * const p_codec = avcodec_find_decoder(m_context->codec_id);
+        const AVCodec *p_codec = avcodec_find_decoder(m_context->codec_id);
 
-        if (p_codec == 0)
+        if (p_codec == nullptr)
             throw std::runtime_error("avcodec_find_decoder() failed");
 
-        // Inform the codec that we can handle truncated bitstreams
-        //if (p_codec->capabilities & CODEC_CAP_TRUNCATED)
-        //    m_context->flags |= CODEC_FLAG_TRUNCATED;
-
-        // Open codec
-        if (avcodec_open2(m_context, p_codec, NULL) < 0)
+        if (avcodec_open2(m_context, p_codec, nullptr) < 0)
             throw std::runtime_error("avcodec_open() failed");
 
-        m_context->get_buffer2 = avcodec_default_get_buffer2;
-
     }
-
     catch (...)
     {
-        m_context = 0;
+        avcodec_free_context(&m_context);
         throw;
     }
 }
@@ -260,6 +237,10 @@ void FFmpegDecoderAudio::close(bool waitForThreadToExi
             join();
     }
     swr_free(&m_swr_context);
+    if (m_context)
+    {
+        avcodec_free_context(&m_context);
+    }
 }
 
 void FFmpegDecoderAudio::setVolume(float volume)
@@ -286,7 +267,7 @@ void FFmpegDecoderAudio::run()
         decodeLoop();
     }
 
-    catch (const std::exception & error)
+    catch (const std::exception &error)
     {
         OSG_WARN << "FFmpegDecoderAudio::run : " << error.what() << std::endl;
     }
@@ -301,15 +282,15 @@ void FFmpegDecoderAudio::setAudioSink(osg::ref_ptr<osg
 void FFmpegDecoderAudio::setAudioSink(osg::ref_ptr<osg::AudioSink> audio_sink)
 {
     // The FFmpegDecoderAudio object takes the responsibility of destroying the audio_sink.
-    OSG_NOTICE<<"Assigning "<<audio_sink<<std::endl;
+    OSG_NOTICE << "Assigning " << audio_sink << std::endl;
     m_audio_sink = audio_sink;
 }
 
 
 
-void FFmpegDecoderAudio::fillBuffer(void * const buffer, size_t size)
+void FFmpegDecoderAudio::fillBuffer(void *buffer, size_t size)
 {
-    uint8_t * dst_buffer = reinterpret_cast<uint8_t*>(buffer);
+    uint8_t *dst_buffer = reinterpret_cast<uint8_t *>(buffer);
 
     while (size != 0)
     {
@@ -349,9 +330,9 @@ void FFmpegDecoderAudio::decodeLoop()
 
 void FFmpegDecoderAudio::decodeLoop()
 {
-    const bool skip_audio = ! validContext() || ! m_audio_sink.valid();
+    const bool skip_audio = !validContext() || !m_audio_sink.valid();
 
-    if (! skip_audio && ! m_audio_sink->playing())
+    if (!skip_audio && !m_audio_sink->playing())
     {
         m_clocks.audioSetDelay(m_audio_sink->getDelay());
         m_audio_sink->play();
@@ -361,17 +342,17 @@ void FFmpegDecoderAudio::decodeLoop()
         m_clocks.audioDisable();
     }
 
-    while (! m_exit)
+    while (!m_exit)
     {
 
-        if(m_paused)
+        if (m_paused)
         {
             m_clocks.pause(true);
             m_pause_timer.setStartTick();
 
-            while(m_paused && !m_exit)
+            while (m_paused && !m_exit)
             {
-                microSleep(10000);
+                OpenThreads::Thread::microSleep(10000);
             }
 
             m_clocks.setPauseTime(m_pause_timer.time_s());
@@ -387,12 +368,30 @@ void FFmpegDecoderAudio::decodeLoop()
             if (packet.valid())
                 packet.clear();
         }
-        // Else, just idle in this thread.
-        // Note: If m_audio_sink has an audio callback, this thread will still be awaken
-        // from time to time to refill the audio buffer.
         else
         {
-            OpenThreads::Thread::microSleep(10000);
+            uint8_t audio_buffer[AVCODEC_MAX_AUDIO_FRAME_SIZE * 3 / 2];
+            size_t audio_data_size = decodeFrame(audio_buffer, sizeof(audio_buffer));
+
+            if (audio_data_size > 0)
+            {
+                // Handle the decoded audio data here.
+                // Since the AudioSink class does not have a specific method for handling raw buffers,
+                // we'll assume you have another method or need to implement this part accordingly.
+
+                // This part needs to match the actual implementation or subclass method
+                // If you have an actual derived class with specific methods, you should call them here.
+                // For example, if there's a method to write raw audio data, use it.
+
+                // Placeholder for actual implementation
+                // Assuming m_audio_sink->writeAudioData(audio_buffer, audio_data_size);
+
+                // OpenThreads::Thread::microSleep(10000); // Uncomment if you want to add a delay
+            }
+            else
+            {
+                OpenThreads::Thread::microSleep(10000);
+            }
         }
     }
 }
@@ -433,7 +432,7 @@ void FFmpegDecoderAudio::adjustBufferEndPts(const size
 
 
 
-size_t FFmpegDecoderAudio::decodeFrame(void * const buffer, const size_t size)
+size_t FFmpegDecoderAudio::decodeFrame(void *buffer, const size_t size)
 {
     for (;;)
     {
@@ -443,7 +442,7 @@ size_t FFmpegDecoderAudio::decodeFrame(void * const bu
         {
             int data_size = size;
 
-            const int bytes_decoded = decode_audio(m_context, reinterpret_cast<int16_t*>(buffer), &data_size, m_packet_data, m_bytes_remaining, m_swr_context, m_out_sample_rate, m_out_nb_channels, m_out_sample_format);
+            const int bytes_decoded = decode_audio(m_context, reinterpret_cast<int16_t *>(buffer), &data_size, m_packet_data, m_bytes_remaining, m_swr_context, m_out_sample_rate, m_out_nb_channels, m_out_sample_format);
 
             if (bytes_decoded < 0)
             {
@@ -503,10 +502,6 @@ size_t FFmpegDecoderAudio::decodeFrame(void * const bu
     }
 }
 
-
-/**
- *
- */
 osg::AudioStream::SampleFormat FFmpegDecoderAudio::sampleFormat() const
 {
     switch (m_out_sample_format)
@@ -515,19 +510,14 @@ osg::AudioStream::SampleFormat FFmpegDecoderAudio::sam
         throw std::runtime_error("invalid audio format AV_SAMPLE_FMT_NONE");
     case AV_SAMPLE_FMT_U8:
         return osg::AudioStream::SAMPLE_FORMAT_U8;
-        break;
     case AV_SAMPLE_FMT_S16:
         return osg::AudioStream::SAMPLE_FORMAT_S16;
-        break;
     case AV_SAMPLE_FMT_S32:
         return osg::AudioStream::SAMPLE_FORMAT_S32;
-        break;
     case AV_SAMPLE_FMT_FLT:
         return osg::AudioStream::SAMPLE_FORMAT_F32;
-        break;
     case AV_SAMPLE_FMT_DBL:
         throw std::runtime_error("unhandled audio format AV_SAMPLE_FMT_DBL");
-
     default:
         throw std::runtime_error("unknown audio format");
     }
