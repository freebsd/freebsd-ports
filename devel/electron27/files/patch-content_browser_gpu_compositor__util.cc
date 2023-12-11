--- content/browser/gpu/compositor_util.cc.orig	2023-02-01 18:43:19 UTC
+++ content/browser/gpu/compositor_util.cc
@@ -148,7 +148,7 @@ const GpuFeatureData GetGpuFeatureData(
     {"video_decode",
      SafeGetFeatureStatus(gpu_feature_info,
                           gpu::GPU_FEATURE_TYPE_ACCELERATED_VIDEO_DECODE),
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
      !base::FeatureList::IsEnabled(media::kVaapiVideoDecodeLinux) ||
 #endif  // BUILDFLAG(IS_LINUX)
          command_line.HasSwitch(switches::kDisableAcceleratedVideoDecode),
@@ -159,7 +159,7 @@ const GpuFeatureData GetGpuFeatureData(
     {"video_encode",
      SafeGetFeatureStatus(gpu_feature_info,
                           gpu::GPU_FEATURE_TYPE_ACCELERATED_VIDEO_ENCODE),
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
      !base::FeatureList::IsEnabled(media::kVaapiVideoEncodeLinux),
 #else
      command_line.HasSwitch(switches::kDisableAcceleratedVideoEncode),
