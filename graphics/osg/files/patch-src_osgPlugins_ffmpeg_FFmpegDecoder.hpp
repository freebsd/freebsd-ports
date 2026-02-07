--- src/osgPlugins/ffmpeg/FFmpegDecoder.hpp.orig	2022-12-01 18:17:31 UTC
+++ src/osgPlugins/ffmpeg/FFmpegDecoder.hpp
@@ -1,4 +1,3 @@
-
 #ifndef HEADER_GUARD_OSGFFMPEG_FFMPEG_DECODER_H
 #define HEADER_GUARD_OSGFFMPEG_FFMPEG_DECODER_H
 
@@ -7,73 +6,76 @@
 
 #include <osg/Notify>
 
-
 namespace osgFFmpeg {
 
 class FFmpegParameters;
 
 class FormatContextPtr
 {
-    public:
-    
-        typedef AVFormatContext T;
-    
-        explicit FormatContextPtr() : _ptr(0) {}
-        explicit FormatContextPtr(T* ptr) : _ptr(ptr) {}
-        
-        ~FormatContextPtr()
-        {
-            cleanup();
-        }
-        
-        T* get() { return _ptr; }
+public:
+    typedef AVFormatContext T;
 
-        operator bool() const { return _ptr != 0; }
+    explicit FormatContextPtr() : _ptr(nullptr) {}
+    explicit FormatContextPtr(T* ptr) : _ptr(ptr) {}
 
-        T * operator-> () const // never throws
-        {
-            return _ptr;
-        }
+    ~FormatContextPtr()
+    {
+        cleanup();
+    }
 
-        void reset(T* ptr) 
-        {
-            if (ptr==_ptr) return;
-            cleanup();
-            _ptr = ptr;
-        }
+    T* get() const { return _ptr; }
+    T** getPtr() { return &_ptr; }
 
-        void cleanup()
+    operator T*() const { return _ptr; }
+
+    FormatContextPtr& operator=(T* ptr)
+    {
+        reset(ptr);
+        return *this;
+    }
+
+    bool operator==(std::nullptr_t) const { return _ptr == nullptr; }
+    bool operator!=(std::nullptr_t) const { return _ptr != nullptr; }
+
+    T* operator->() const // never throws
+    {
+        return _ptr;
+    }
+
+    void reset(T* ptr)
+    {
+        if (ptr == _ptr) return;
+        cleanup();
+        _ptr = ptr;
+    }
+
+    void cleanup()
+    {
+        if (_ptr)
         {
-            if (_ptr) 
-            {
 #if LIBAVCODEC_VERSION_INT >= AV_VERSION_INT(53, 17, 0)
-                OSG_NOTICE<<"Calling avformat_close_input("<<&_ptr<<")"<<std::endl;
-                avformat_close_input(&_ptr);
+            OSG_NOTICE << "Calling avformat_close_input(" << &_ptr << ")" << std::endl;
+            avformat_close_input(&_ptr);
 #else
-                OSG_NOTICE<<"Calling av_close_input_file("<<_ptr<<")"<<std::endl;
-                av_close_input_file(_ptr);
+            OSG_NOTICE << "Calling av_close_input_file(" << _ptr << ")" << std::endl;
+            av_close_input_file(_ptr);
 #endif
-            }
-            _ptr = 0;
         }
-        
-        
+        _ptr = nullptr;
+    }
 
-    protected:
-    
-        T* _ptr;
+protected:
+    T* _ptr;
 };
 
-
 class FFmpegDecoder : public osg::Referenced
 {
 public:
-
     FFmpegDecoder();
     ~FFmpegDecoder();
 
-    bool open(const std::string & filename, FFmpegParameters* parameters);
-    void close(bool waitForThreadToExit);
+    bool open(const std::string& filename, FFmpegParameters* parameters);
+    void close(bool waitForThreadToExit = true);
 
     bool readNextPacket();
     void rewind();
@@ -87,13 +89,12 @@ class FFmpegDecoder : public osg::Referenced (public)
     double duration() const;
     double reference();
 
-    FFmpegDecoderAudio & audio_decoder();
-    FFmpegDecoderVideo & video_decoder();
-    FFmpegDecoderAudio const & audio_decoder() const;
-    FFmpegDecoderVideo const & video_decoder() const;
+    FFmpegDecoderAudio& audio_decoder();
+    FFmpegDecoderVideo& video_decoder();
+    FFmpegDecoderAudio const& audio_decoder() const;
+    FFmpegDecoderVideo const& video_decoder() const;
 
 protected:
-
     enum State
     {
         NORMAL,
@@ -115,38 +116,33 @@ class FFmpegDecoder : public osg::Referenced (public)
     void rewindButDontFlushQueues();
     void seekButDontFlushQueues(double time);
 
-    FormatContextPtr    m_format_context;
-    AVStream *          m_audio_stream;
-    AVStream *          m_video_stream;
+    FormatContextPtr m_format_context;
+    AVStream* m_audio_stream;
+    AVStream* m_video_stream;
 
-    int                 m_audio_index;
-    int                 m_video_index;
+    int m_audio_index;
+    int m_video_index;
 
-    FFmpegClocks        m_clocks;
-    FFmpegPacket        m_pending_packet;
-    PacketQueue         m_audio_queue;
-    PacketQueue         m_video_queue;
-    
-    FFmpegDecoderAudio  m_audio_decoder;
-    FFmpegDecoderVideo  m_video_decoder;
+    FFmpegClocks m_clocks;
+    FFmpegPacket m_pending_packet;
+    PacketQueue m_audio_queue;
+    PacketQueue m_video_queue;
 
-    double              m_duration;
-    double              m_start;
+    FFmpegDecoderAudio m_audio_decoder;
+    FFmpegDecoderVideo m_video_decoder;
 
-    State               m_state;
-    bool                m_loop;
+    double m_duration;
+    double m_start;
+
+    State m_state;
+    bool m_loop;
 };
 
-
-
-
-
 inline void FFmpegDecoder::loop(const bool loop)
 {
     m_loop = loop;
 }
 
-
 inline bool FFmpegDecoder::loop() const
 {
     return m_loop;
@@ -154,8 +150,8 @@ inline double FFmpegDecoder::creation_time() const
 
 inline double FFmpegDecoder::creation_time() const
 {
-   if(m_format_context) return m_format_context->start_time;
-   else return HUGE_VAL;
+    if (m_format_context) return m_format_context->start_time;
+    else return HUGE_VAL;
 }
 
 inline double FFmpegDecoder::duration() const
@@ -165,37 +161,30 @@ inline double FFmpegDecoder::reference()
 
 inline double FFmpegDecoder::reference()
 {
-    return m_clocks.getCurrentTime();    
+    return m_clocks.getCurrentTime();
 }
 
-
-inline FFmpegDecoderAudio & FFmpegDecoder::audio_decoder()
+inline FFmpegDecoderAudio& FFmpegDecoder::audio_decoder()
 {
     return m_audio_decoder;
 }
 
-
-inline FFmpegDecoderVideo & FFmpegDecoder::video_decoder()
+inline FFmpegDecoderVideo& FFmpegDecoder::video_decoder()
 {
     return m_video_decoder;
 }
 
-
-inline FFmpegDecoderAudio const & FFmpegDecoder::audio_decoder() const
+inline FFmpegDecoderAudio const& FFmpegDecoder::audio_decoder() const
 {
     return m_audio_decoder;
 }
 
-
-inline FFmpegDecoderVideo const & FFmpegDecoder::video_decoder() const
+inline FFmpegDecoderVideo const& FFmpegDecoder::video_decoder() const
 {
     return m_video_decoder;
 }
 
-
-
 } // namespace osgFFmpeg
 
-
-
 #endif // HEADER_GUARD_OSGFFMPEG_FFMPEG_DECODER_H
+
