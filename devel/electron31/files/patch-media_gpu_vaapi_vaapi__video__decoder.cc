--- media/gpu/vaapi/vaapi_video_decoder.cc.orig	2024-06-18 21:43:35 UTC
+++ media/gpu/vaapi/vaapi_video_decoder.cc
@@ -775,7 +775,7 @@ void VaapiVideoDecoder::ApplyResolutionChangeWithScree
   const gfx::Size decoder_natural_size =
       aspect_ratio_.GetNaturalSize(decoder_visible_rect);
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   std::optional<DmabufVideoFramePool::CreateFrameCB> allocator =
       base::BindRepeating(&AllocateCustomFrameProxy, weak_this_);
   std::vector<ImageProcessor::PixelLayoutCandidate> candidates = {
