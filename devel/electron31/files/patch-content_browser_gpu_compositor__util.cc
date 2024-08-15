--- content/browser/gpu/compositor_util.cc.orig	2024-04-15 20:33:57 UTC
+++ content/browser/gpu/compositor_util.cc
@@ -149,7 +149,7 @@ std::vector<GpuFeatureData> GetGpuFeatureData(
       "video_decode",
       SafeGetFeatureStatus(
           gpu_feature_info, gpu::GPU_FEATURE_TYPE_ACCELERATED_VIDEO_DECODE,
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
           !base::FeatureList::IsEnabled(media::kVaapiVideoDecodeLinux) ||
 #endif  // BUILDFLAG(IS_LINUX)
               command_line.HasSwitch(switches::kDisableAcceleratedVideoDecode)),
@@ -161,7 +161,7 @@ std::vector<GpuFeatureData> GetGpuFeatureData(
       "video_encode",
       SafeGetFeatureStatus(
           gpu_feature_info, gpu::GPU_FEATURE_TYPE_ACCELERATED_VIDEO_ENCODE,
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
           !base::FeatureList::IsEnabled(media::kVaapiVideoEncodeLinux)),
 #else
           command_line.HasSwitch(switches::kDisableAcceleratedVideoEncode)),
