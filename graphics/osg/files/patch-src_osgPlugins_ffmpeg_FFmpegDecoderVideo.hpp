--- src/osgPlugins/ffmpeg/FFmpegDecoderVideo.hpp.orig	2022-12-01 18:17:31 UTC
+++ src/osgPlugins/ffmpeg/FFmpegDecoderVideo.hpp
@@ -1,4 +1,3 @@
-
 #ifndef HEADER_GUARD_OSGFFMPEG_FFMPEG_DECODER_VIDEO_H
 #define HEADER_GUARD_OSGFFMPEG_FFMPEG_DECODER_VIDEO_H
 
@@ -15,11 +14,11 @@ class FramePtr
 
 class FramePtr
 {
-    public:
+    public:  
     
         typedef AVFrame T;
     
-        explicit FramePtr() : _ptr(0) {}
+        explicit FramePtr() : _ptr(nullptr) {}
         explicit FramePtr(T* ptr) : _ptr(ptr) {}
         
         ~FramePtr()
@@ -43,14 +42,11 @@ class FramePtr
 
         void cleanup()
         {
-            if (_ptr) av_free(_ptr);
-            _ptr = 0;
+            if (_ptr) av_frame_free(&_ptr);
+            _ptr = nullptr;
         }
         
-        
-
     protected:
-    
         T* _ptr;
 };
 
@@ -88,12 +84,11 @@ class FFmpegDecoderVideo : public OpenThreads::Thread 
     void findAspectRatio();
     void publishFrame(double delay, bool audio_disabled);
     double synchronizeVideo(double pts);
-    void yuva420pToRgba(AVPicture *dst, AVPicture *src, int width, int height);
+    void yuva420pToRgba(AVFrame* dst, AVFrame* src, int width, int height);
 
-    int convert(AVPicture *dst, int dst_pix_fmt, AVPicture *src,
+    int convert(AVFrame* dst, int dst_pix_fmt, AVFrame* src,
                 int src_pix_fmt, int src_width, int src_height);
 
-
     static int getBuffer(AVCodecContext * context, AVFrame * picture, int flags);
     static void freeBuffer(void * opaque, uint8_t *data);
 
@@ -101,7 +96,7 @@ class FFmpegDecoderVideo : public OpenThreads::Thread 
     FFmpegClocks &          m_clocks;
     AVStream *              m_stream;
     AVCodecContext *        m_context;
-    AVCodec *               m_codec;
+    const AVCodec*          m_codec;
     const uint8_t *         m_packet_data;
     int                     m_bytes_remaining;
     int64_t                 m_packet_pts;
