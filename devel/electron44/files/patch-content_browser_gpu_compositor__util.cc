--- content/browser/gpu/compositor_util.cc.orig	2026-03-13 16:54:03 UTC
+++ content/browser/gpu/compositor_util.cc
@@ -143,7 +143,7 @@ std::vector<GpuFeatureData> GetGpuFeatureData(
       "video_decode",
       SafeGetFeatureStatus(
           gpu_feature_info, gpu::GPU_FEATURE_TYPE_ACCELERATED_VIDEO_DECODE,
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
           !base::FeatureList::IsEnabled(media::kAcceleratedVideoDecodeLinux) ||
 #endif  // BUILDFLAG(IS_LINUX)
               command_line.HasSwitch(switches::kDisableAcceleratedVideoDecode)),
@@ -155,7 +155,7 @@ std::vector<GpuFeatureData> GetGpuFeatureData(
       "video_encode",
       SafeGetFeatureStatus(
           gpu_feature_info, gpu::GPU_FEATURE_TYPE_ACCELERATED_VIDEO_ENCODE,
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
           !base::FeatureList::IsEnabled(media::kAcceleratedVideoEncodeLinux)),
 #else
           command_line.HasSwitch(switches::kDisableAcceleratedVideoEncode)),
@@ -217,7 +217,7 @@ std::vector<GpuFeatureData> GetGpuFeatureData(
                             ? gpu::kGpuFeatureStatusEnabled
                             : gpu::kGpuFeatureStatusDisabled);
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   features.emplace_back(
       "webgpu_on_vk_via_gl_interop",
       SafeGetFeatureStatus(gpu_feature_info,
