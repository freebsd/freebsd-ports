--- media/gpu/chromeos/platform_video_frame_utils.cc.orig	2024-06-18 21:43:35 UTC
+++ media/gpu/chromeos/platform_video_frame_utils.cc
@@ -68,7 +68,7 @@ static std::unique_ptr<ui::GbmDevice> CreateGbmDevice(
     const base::FilePath dev_path(FILE_PATH_LITERAL(
         base::StrCat({drm_node_file_prefix, base::NumberToString(i)})));
 
-#if BUILDFLAG(IS_LINUX) && BUILDFLAG(USE_V4L2_CODEC)
+#if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)) && BUILDFLAG(USE_V4L2_CODEC)
     const bool is_render_node = base::Contains(drm_node_file_prefix, "render");
 
     // TODO(b/313513760): don't guard base::File::FLAG_WRITE behind
@@ -196,7 +196,7 @@ class GbmDeviceWrapper {
     const bool is_intel_media_compression_enabled =
 #if BUILDFLAG(IS_CHROMEOS)
         base::FeatureList::IsEnabled(features::kEnableIntelMediaCompression);
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
         false;
 #endif
     if (is_intel_media_compression_enabled) {
@@ -350,7 +350,7 @@ scoped_refptr<VideoFrame> CreateVideoFrameFromGpuMemor
   const bool is_intel_media_compression_enabled =
 #if BUILDFLAG(IS_CHROMEOS)
       base::FeatureList::IsEnabled(features::kEnableIntelMediaCompression);
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
       false;
 #endif
 
