Fix build with ffmpeg 3.x.

--- src/spek-audio.cc.orig	2016-12-28 01:32:07 UTC
+++ src/spek-audio.cc
@@ -199,7 +199,7 @@ AudioFileImpl::AudioFileImpl(
     this->packet.data = nullptr;
     this->packet.size = 0;
     this->offset = 0;
-    this->frame = avcodec_alloc_frame();
+    this->frame = av_frame_alloc();
     this->buffer_size = 0;
     this->buffer = nullptr;
     this->frames_per_interval = 0;
@@ -215,7 +215,7 @@ AudioFileImpl::~AudioFileImpl()
     if (this->frame) {
         // TODO: Remove this check after Debian switches to libav 9.
 #if LIBAVCODEC_VERSION_INT >= AV_VERSION_INT(54, 28, 0)
-        avcodec_free_frame(&this->frame);
+        av_frame_free(&this->frame);
 #else
         av_freep(&this->frame);
 #endif
@@ -224,7 +224,7 @@ AudioFileImpl::~AudioFileImpl()
         this->packet.data -= this->offset;
         this->packet.size += this->offset;
         this->offset = 0;
-        av_free_packet(&this->packet);
+        av_packet_unref(&this->packet);
     }
     if (this->format_context) {
         if (this->audio_stream >= 0) {
@@ -255,7 +255,7 @@ int AudioFileImpl::read()
 
     for (;;) {
         while (this->packet.size > 0) {
-            avcodec_get_frame_defaults(this->frame);
+            av_frame_unref(this->frame);
             auto codec_context = this->format_context->streams[this->audio_stream]->codec;
             int got_frame = 0;
             int len = avcodec_decode_audio4(codec_context, this->frame, &got_frame, &this->packet);
@@ -299,7 +299,7 @@ int AudioFileImpl::read()
             this->packet.data -= this->offset;
             this->packet.size += this->offset;
             this->offset = 0;
-            av_free_packet(&this->packet);
+            av_packet_unref(&this->packet);
         }
 
         int res = 0;
@@ -307,7 +307,7 @@ int AudioFileImpl::read()
             if (this->packet.stream_index == this->audio_stream) {
                 break;
             }
-            av_free_packet(&this->packet);
+            av_packet_unref(&this->packet);
         }
         if (res < 0) {
             // End of file or error.
