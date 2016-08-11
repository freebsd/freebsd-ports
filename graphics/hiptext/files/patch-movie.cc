--- movie.cc.orig	2016-06-21 21:09:17 UTC
+++ movie.cc
@@ -53,7 +53,7 @@ void Movie::PrepareRGB(int width, int he
 
   // Prepare context for scaling and converting to RGB.
   sws_ = sws_getContext(context_->width, context_->height, context_->pix_fmt,
-                        width_, height_, PIX_FMT_RGB24, SWS_FAST_BILINEAR,
+                        width_, height_, AV_PIX_FMT_RGB24, SWS_FAST_BILINEAR,
                         nullptr, nullptr, nullptr);
   CHECK(codec_ = avcodec_find_decoder(context_->codec_id))
       << "Unsupported codec.\n";
@@ -61,13 +61,13 @@ void Movie::PrepareRGB(int width, int he
       << "Could not open codec.\n";
 
   // Allocate Raw + RGB frame buffers.
-  CHECK(frame_ = avcodec_alloc_frame());
-  CHECK(frame_rgb_ = avcodec_alloc_frame());
-  int rgb_bytes = avpicture_get_size(PIX_FMT_RGB24, width_, height_);
+  CHECK(frame_ = av_frame_alloc());
+  CHECK(frame_rgb_ = av_frame_alloc());
+  int rgb_bytes = avpicture_get_size(AV_PIX_FMT_RGB24, width_, height_);
   buffer_ = static_cast<uint8_t*>(av_malloc(rgb_bytes));
   LOG(INFO) << "RGB Buffer: " << rgb_bytes << " bytes.";
   int prep = avpicture_fill(reinterpret_cast<AVPicture*>(frame_rgb_),
-                            buffer_, PIX_FMT_RGB24, width_, height_);
+                            buffer_, AV_PIX_FMT_RGB24, width_, height_);
   CHECK_GE(prep, 0) << "Failed to prepare RGB buffer.";
   LOG(INFO) << "RGB dimensions: " << width_  << "x" << height_;
 }
