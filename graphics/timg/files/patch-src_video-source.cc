--- src/video-source.cc.orig	2025-09-01 04:23:46 UTC
+++ src/video-source.cc
@@ -111,7 +111,6 @@ VideoSource::~VideoSource() {
 
 VideoSource::~VideoSource() {
     sws_freeContext(sws_context_);
-    avcodec_close(codec_context_);
     avcodec_free_context(&codec_context_);
     avformat_close_input(&format_context_);
     delete terminal_fb_;
