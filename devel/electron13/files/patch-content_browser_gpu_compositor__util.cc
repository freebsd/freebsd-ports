--- content/browser/gpu/compositor_util.cc.orig	2021-07-15 19:13:39 UTC
+++ content/browser/gpu/compositor_util.cc
@@ -127,11 +127,11 @@ const GpuFeatureData GetGpuFeatureData(
     {"video_decode",
      SafeGetFeatureStatus(gpu_feature_info,
                           gpu::GPU_FEATURE_TYPE_ACCELERATED_VIDEO_DECODE),
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
      !base::FeatureList::IsEnabled(media::kVaapiVideoDecodeLinux),
 #else
      command_line.HasSwitch(switches::kDisableAcceleratedVideoDecode),
-#endif  // defined(OS_LINUX)
+#endif  // defined(OS_LINUX) || defined(OS_BSD)
      DisableInfo::Problem(
          "Accelerated video decode has been disabled, either via blocklist, "
          "about:flags or the command line."),
