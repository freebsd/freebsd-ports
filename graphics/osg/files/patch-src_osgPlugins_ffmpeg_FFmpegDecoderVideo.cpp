--- src/osgPlugins/ffmpeg/FFmpegDecoderVideo.cpp.orig	2022-12-01 18:17:31 UTC
+++ src/osgPlugins/ffmpeg/FFmpegDecoderVideo.cpp
@@ -6,38 +6,35 @@
 #include <stdexcept>
 #include <string.h>
 
+extern "C" {
+#include <libavutil/imgutils.h>
+}
+
 namespace osgFFmpeg {
 
-// TODO - add support for using RGB or RGBA pixel format.
-// Note from Jason Daly in a osg-submissions thread, "The pix_fmt field of AVCodecContext will indicate the pixel format of the decoded video"
-
-
 FFmpegDecoderVideo::FFmpegDecoderVideo(PacketQueue & packets, FFmpegClocks & clocks) :
     m_packets(packets),
     m_clocks(clocks),
-    m_stream(0),
-    m_context(0),
-    m_codec(0),
-    m_packet_data(0),
+    m_stream(nullptr),
+    m_context(nullptr),
+    m_codec(nullptr),
+    m_packet_data(nullptr),
     m_bytes_remaining(0),
     m_packet_pts(AV_NOPTS_VALUE),
     m_writeBuffer(0),
-    m_user_data(0),
-    m_publish_func(0),
+    m_user_data(nullptr),
+    m_publish_func(nullptr),
     m_paused(true),
     m_exit(false)
 #ifdef USE_SWSCALE
-    ,m_swscale_ctx(0)
+    ,m_swscale_ctx(nullptr)
 #endif
 {
-
 }
 
-
-
 FFmpegDecoderVideo::~FFmpegDecoderVideo()
 {
-    OSG_INFO<<"Destructing FFmpegDecoderVideo..."<<std::endl;
+    OSG_INFO << "Destructing FFmpegDecoderVideo..." << std::endl;
 
     this->close(true);
 
@@ -45,24 +42,23 @@ FFmpegDecoderVideo::~FFmpegDecoderVideo()
     if (m_swscale_ctx)
     {
         sws_freeContext(m_swscale_ctx);
-        m_swscale_ctx = 0;
+        m_swscale_ctx = nullptr;
     }
 #endif
 
     if (m_context)
     {
-        avcodec_close(m_context);
+        avcodec_free_context(&m_context);
     }
 
-    OSG_INFO<<"Destructed FFmpegDecoderVideo"<<std::endl;
+    OSG_INFO << "Destructed FFmpegDecoderVideo" << std::endl;
 }
 
-
-
 void FFmpegDecoderVideo::open(AVStream * const stream)
 {
     m_stream = stream;
-    m_context = stream->codec;
+    m_context = avcodec_alloc_context3(nullptr);
+    avcodec_parameters_to_context(m_context, stream->codecpar);
 
     // Trust the video size given at this point
     // (avcodec_open seems to sometimes return a 0x0 size)
@@ -74,43 +70,34 @@ void FFmpegDecoderVideo::open(AVStream * const stream)
     m_alpha_channel = (m_context->pix_fmt == AV_PIX_FMT_YUVA420P);
 
     // Find out the framerate
-    #if LIBAVCODEC_VERSION_MAJOR >= 56
     m_frame_rate = av_q2d(stream->avg_frame_rate);
-    #else
-    m_frame_rate = av_q2d(stream->r_frame_rate);
-    #endif
 
     // Find the decoder for the video stream
     m_codec = avcodec_find_decoder(m_context->codec_id);
 
-    if (m_codec == 0)
+    if (m_codec == nullptr)
         throw std::runtime_error("avcodec_find_decoder() failed");
 
-    // Inform the codec that we can handle truncated bitstreams
-    //if (p_codec->capabilities & CODEC_CAP_TRUNCATED)
-    //    m_context->flags |= CODEC_FLAG_TRUNCATED;
-
     // Open codec
-    if (avcodec_open2(m_context, m_codec, NULL) < 0)
-        throw std::runtime_error("avcodec_open() failed");
+    if (avcodec_open2(m_context, m_codec, nullptr) < 0)
+        throw std::runtime_error("avcodec_open2() failed");
 
     // Allocate video frame
     m_frame.reset(av_frame_alloc());
 
     // Allocate converted RGB frame
     m_frame_rgba.reset(av_frame_alloc());
-    m_buffer_rgba[0].resize(avpicture_get_size(AV_PIX_FMT_RGB24, width(), height()));
+    m_buffer_rgba[0].resize(av_image_get_buffer_size(AV_PIX_FMT_RGB24, width(), height(), 1));
     m_buffer_rgba[1].resize(m_buffer_rgba[0].size());
 
     // Assign appropriate parts of the buffer to image planes in m_frame_rgba
-    avpicture_fill((AVPicture *) (m_frame_rgba).get(), &(m_buffer_rgba[0])[0], AV_PIX_FMT_RGB24, width(), height());
+    av_image_fill_arrays(m_frame_rgba->data, m_frame_rgba->linesize, &(m_buffer_rgba[0])[0], AV_PIX_FMT_RGB24, width(), height(), 1);
 
-    // Override get_buffer()/release_buffer() from codec context in order to retrieve the PTS of each frame.
+    // Override get_buffer2() from codec context in order to retrieve the PTS of each frame.
     m_context->opaque = this;
     m_context->get_buffer2 = getBuffer;
 }
 
-
 void FFmpegDecoderVideo::close(bool waitForThreadToExit)
 {
     if (isRunning())
@@ -123,10 +110,7 @@ void FFmpegDecoderVideo::pause(bool pause)
 
 void FFmpegDecoderVideo::pause(bool pause)
 {
-    if(pause)
-        m_paused = true;
-    else
-        m_paused = false;
+    m_paused = pause;
 }
 
 void FFmpegDecoderVideo::run()
@@ -135,102 +119,60 @@ void FFmpegDecoderVideo::run()
     {
         decodeLoop();
     }
-
-    catch (const std::exception & error)
+    catch (const std::exception &error)
     {
         OSG_WARN << "FFmpegDecoderVideo::run : " << error.what() << std::endl;
     }
-
     catch (...)
     {
         OSG_WARN << "FFmpegDecoderVideo::run : unhandled exception" << std::endl;
     }
 }
 
-
-
 void FFmpegDecoderVideo::decodeLoop()
 {
     FFmpegPacket packet;
     double pts;
 
-    while (! m_exit)
+    while (!m_exit)
     {
         // Work on the current packet until we have decoded all of it
-
         while (m_bytes_remaining > 0)
         {
             // Save global PTS to be stored in m_frame via getBuffer()
-
             m_packet_pts = packet.packet.pts;
 
             // Decode video frame
-
             int frame_finished = 0;
+            const int bytes_decoded = avcodec_receive_frame(m_context, m_frame.get());
 
-            // We want to use the entire packet since some codecs will require extra information for decoding
-            const int bytes_decoded = avcodec_decode_video2(m_context, m_frame.get(), &frame_finished, &(packet.packet));
+            if (bytes_decoded == 0)
+            {
+                frame_finished = 1;
+                m_bytes_remaining -= bytes_decoded;
+                m_packet_data += bytes_decoded;
+            }
+            else if (bytes_decoded == AVERROR(EAGAIN))
+            {
+                break;
+            }
+            else if (bytes_decoded < 0)
+            {
+                throw std::runtime_error("avcodec_receive_frame() failed");
+            }
 
-            if (bytes_decoded < 0)
-                throw std::runtime_error("avcodec_decode_video failed()");
-
-            m_bytes_remaining -= bytes_decoded;
-            m_packet_data += bytes_decoded;
-
             // Publish the frame if we have decoded a complete frame
             if (frame_finished)
             {
-#if LIBAVCODEC_VERSION_INT <= AV_VERSION_INT(57,24,102)
-                //ffmpeg-3.0 and below
-                AVRational timebase;
-                // Find out the frame pts
-                if (m_frame->pts != int64_t(AV_NOPTS_VALUE))
+                if (m_frame->pts != AV_NOPTS_VALUE)
                 {
-                    pts = m_frame->pts;
-                    timebase = m_context->time_base;
-                }
-                else if (packet.packet.dts == int64_t(AV_NOPTS_VALUE) &&
-                        m_frame->opaque != 0 &&
-                        *reinterpret_cast<const int64_t*>(m_frame->opaque) != int64_t(AV_NOPTS_VALUE))
-                {
-                    pts = *reinterpret_cast<const int64_t*>(m_frame->opaque);
-                    timebase = m_stream->time_base;
-                }
-                else if (packet.packet.dts != int64_t(AV_NOPTS_VALUE))
-                {
-                    pts = packet.packet.dts;
-                    timebase = m_stream->time_base;
-                }
-                else
-                {
-                    pts = 0;
-                    timebase = m_context->time_base;
-                }
-
-                pts *= av_q2d(timebase);
-
-#else
-                //above ffmpeg-3.0
-                // Find out the frame pts
-                if (m_frame->pts != int64_t(AV_NOPTS_VALUE))
-                {
                     pts = av_q2d(m_stream->time_base) * m_frame->pts;
                 }
-                else if (packet.packet.dts == int64_t(AV_NOPTS_VALUE) &&
-                        m_frame->opaque != 0 &&
-                        *reinterpret_cast<const int64_t*>(m_frame->opaque) != int64_t(AV_NOPTS_VALUE))
-                {
-                    pts = av_q2d(m_stream->time_base) * *reinterpret_cast<const int64_t*>(m_frame->opaque);
-                }
-                else if (packet.packet.dts != int64_t(AV_NOPTS_VALUE))
-                {
-                    pts = av_q2d(m_stream->time_base) * packet.packet.dts;
-                }
                 else
                 {
                     pts = 0;
                 }
-#endif
+
                 const double synched_pts = m_clocks.videoSynchClock(m_frame.get(), av_q2d(av_inv_q(m_context->framerate)), pts);
                 const double frame_delay = m_clocks.videoRefreshSchedule(synched_pts);
 
@@ -238,13 +180,12 @@ void FFmpegDecoderVideo::decodeLoop()
             }
         }
 
-        while(m_paused && !m_exit)
+        while (m_paused && !m_exit)
         {
-            microSleep(10000);
+            OpenThreads::Thread::microSleep(10000);
         }
 
         // Get the next packet
-
         pts = 0;
 
         if (packet.valid())
@@ -253,12 +194,13 @@ void FFmpegDecoderVideo::decodeLoop()
         bool is_empty = true;
         packet = m_packets.timedPop(is_empty, 10);
 
-        if (! is_empty)
+        if (!is_empty)
         {
             if (packet.type == FFmpegPacket::PACKET_DATA)
             {
                 m_bytes_remaining = packet.packet.size;
                 m_packet_data = packet.packet.data;
+                avcodec_send_packet(m_context, &(packet.packet));
             }
             else if (packet.type == FFmpegPacket::PACKET_FLUSH)
             {
@@ -268,8 +210,6 @@ void FFmpegDecoderVideo::decodeLoop()
     }
 }
 
-
-
 void FFmpegDecoderVideo::findAspectRatio()
 {
     float ratio = 0.0f;
@@ -283,65 +223,52 @@ void FFmpegDecoderVideo::findAspectRatio()
     m_pixel_aspect_ratio = ratio;
 }
 
-int FFmpegDecoderVideo::convert(AVPicture *dst, int dst_pix_fmt, AVPicture *src,
-            int src_pix_fmt, int src_width, int src_height)
+int FFmpegDecoderVideo::convert(AVFrame *dst, int dst_pix_fmt, AVFrame *src,
+                                int src_pix_fmt, int src_width, int src_height)
 {
     osg::Timer_t startTick = osg::Timer::instance()->tick();
 #ifdef USE_SWSCALE
-    if (m_swscale_ctx==0)
+    if (m_swscale_ctx == nullptr)
     {
-        m_swscale_ctx = sws_getContext(src_width, src_height, (AVPixelFormat) src_pix_fmt,
-                                      src_width, src_height, (AVPixelFormat) dst_pix_fmt,
-                                      /*SWS_BILINEAR*/ SWS_BICUBIC, NULL, NULL, NULL);
+        m_swscale_ctx = sws_getContext(src_width, src_height, (AVPixelFormat)src_pix_fmt,
+                                       src_width, src_height, (AVPixelFormat)dst_pix_fmt,
+                                       SWS_BICUBIC, nullptr, nullptr, nullptr);
     }
 
+    OSG_DEBUG << "Using sws_scale ";
 
-    OSG_DEBUG<<"Using sws_scale ";
-
-    int result =  sws_scale(m_swscale_ctx,
-                            (src->data), (src->linesize), 0, src_height,
-                            (dst->data), (dst->linesize));
+    int result = sws_scale(m_swscale_ctx,
+                           src->data, src->linesize, 0, src_height,
+                           dst->data, dst->linesize);
 #else
 
-    OSG_DEBUG<<"Using img_convert ";
+    OSG_DEBUG << "Using img_convert ";
 
-    int result = img_convert(dst, dst_pix_fmt, src,
-                             src_pix_fmt, src_width, src_height);
-
+    int result = av_image_copy_to_buffer(dst->data, dst_pix_fmt, src->data, src_pix_fmt, src_width, src_height);
 #endif
     osg::Timer_t endTick = osg::Timer::instance()->tick();
-    OSG_DEBUG<<" time = "<<osg::Timer::instance()->delta_m(startTick,endTick)<<"ms"<<std::endl;
+    OSG_DEBUG << " time = " << osg::Timer::instance()->delta_m(startTick, endTick) << "ms" << std::endl;
 
     return result;
 }
 
-
 void FFmpegDecoderVideo::publishFrame(const double delay, bool audio_disabled)
 {
     // If no publishing function, just ignore the frame
-    if (m_publish_func == 0)
+    if (m_publish_func == nullptr)
         return;
 
-#if 1
-    // new code from Jean-Sebasiten Guay - needs testing as we're unclear on the best solution
     // If the display delay is too small, we better skip the frame.
     if (!audio_disabled && delay < -0.010)
         return;
-#else
-    // original solution that hung on video stream over web.
-    // If the display delay is too small, we better skip the frame.
-    if (delay < -0.010)
-        return;
-#endif
 
-    AVPicture * const src = (AVPicture *) m_frame.get();
-    AVPicture * const dst = (AVPicture *) m_frame_rgba.get();
+    AVFrame *src = m_frame.get();
+    AVFrame *dst = m_frame_rgba.get();
 
     // Assign appropriate parts of the buffer to image planes in m_frame_rgba
-    avpicture_fill((AVPicture *) (m_frame_rgba).get(), &(m_buffer_rgba[m_writeBuffer])[0], AV_PIX_FMT_RGB24, width(), height());
+    av_image_fill_arrays(dst->data, dst->linesize, &(m_buffer_rgba[m_writeBuffer])[0], AV_PIX_FMT_RGB24, width(), height(), 1);
 
     // Convert YUVA420p (i.e. YUV420p plus alpha channel) using our own routine
-
     if (m_context->pix_fmt == AV_PIX_FMT_YUVA420P)
         yuva420pToRgba(dst, src, width(), height());
     else
@@ -363,26 +290,25 @@ void FFmpegDecoderVideo::publishFrame(const double del
         i_delay -= micro_delay;
     }
 
-    m_writeBuffer = 1-m_writeBuffer;
+    m_writeBuffer = 1 - m_writeBuffer;
 
-    m_publish_func(* this, m_user_data);
+    m_publish_func(*this, m_user_data);
 }
 
-
-
-void FFmpegDecoderVideo::yuva420pToRgba(AVPicture * const dst, AVPicture * const src, int width, int height)
+void FFmpegDecoderVideo::yuva420pToRgba(AVFrame * const dst, AVFrame * const src, int width, int height)
 {
     convert(dst, AV_PIX_FMT_RGB24, src, m_context->pix_fmt, width, height);
 
     const size_t bpp = 4;
 
-    uint8_t * a_dst = dst->data[0] + 3;
+    uint8_t *a_dst = dst->data[0] + 3;
 
-    for (int h = 0; h < height; ++h) {
+    for (int h = 0; h < height; ++h)
+    {
+        const uint8_t *a_src = src->data[3] + h * src->linesize[3];
 
-        const uint8_t * a_src = src->data[3] + h * src->linesize[3];
-
-        for (int w = 0; w < width; ++w) {
+        for (int w = 0; w < width; ++w)
+        {
             *a_dst = *a_src;
             a_dst += bpp;
             a_src += 1;
@@ -396,7 +322,7 @@ int FFmpegDecoderVideo::getBuffer(AVCodecContext * con
     const FFmpegDecoderVideo * const this_ = reinterpret_cast<const FFmpegDecoderVideo*>(context->opaque);
 
     const int result = avcodec_default_get_buffer2(context, picture, flags);
-    int64_t * p_pts = reinterpret_cast<int64_t*>( av_malloc(sizeof(int64_t)) );
+    int64_t *p_pts = reinterpret_cast<int64_t*>(av_malloc(sizeof(int64_t)));
 
     *p_pts = this_->m_packet_pts;
     picture->opaque = p_pts;
@@ -415,3 +341,4 @@ void FFmpegDecoderVideo::freeBuffer(void *opaque, uint
 }
 
 } // namespace osgFFmpeg
+
