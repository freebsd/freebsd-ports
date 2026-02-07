--- media/gpu/v4l2/v4l2_utils.cc.orig	2025-10-21 20:19:54 UTC
+++ media/gpu/v4l2/v4l2_utils.cc
@@ -18,7 +18,7 @@
 #include <map>
 #include <sstream>
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include <drm_fourcc.h>
 #endif
 
@@ -244,7 +244,7 @@ std::optional<VideoFrameLayout> V4L2FormatToVideoFrame
   }
   const VideoPixelFormat video_format = video_fourcc->ToVideoPixelFormat();
   uint64_t modifiers = gfx::NativePixmapHandle::kNoModifier;
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   if (video_fourcc == Fourcc(Fourcc::MM21)) {
     modifiers = DRM_FORMAT_MOD_MTK_16L_32S_TILE;
   }
