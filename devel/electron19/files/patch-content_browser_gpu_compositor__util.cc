--- content/browser/gpu/compositor_util.cc.orig	2022-05-25 04:01:00 UTC
+++ content/browser/gpu/compositor_util.cc
@@ -148,7 +148,7 @@ const GpuFeatureData GetGpuFeatureData(
     {"video_decode",
      SafeGetFeatureStatus(gpu_feature_info,
                           gpu::GPU_FEATURE_TYPE_ACCELERATED_VIDEO_DECODE),
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
      !base::FeatureList::IsEnabled(media::kVaapiVideoDecodeLinux),
 #else
      command_line.HasSwitch(switches::kDisableAcceleratedVideoDecode),
@@ -160,7 +160,7 @@ const GpuFeatureData GetGpuFeatureData(
     {"video_encode",
      SafeGetFeatureStatus(gpu_feature_info,
                           gpu::GPU_FEATURE_TYPE_ACCELERATED_VIDEO_ENCODE),
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
      !base::FeatureList::IsEnabled(media::kVaapiVideoEncodeLinux),
 #else
      command_line.HasSwitch(switches::kDisableAcceleratedVideoEncode),
