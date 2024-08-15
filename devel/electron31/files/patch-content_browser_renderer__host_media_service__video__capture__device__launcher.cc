--- content/browser/renderer_host/media/service_video_capture_device_launcher.cc.orig	2024-06-18 21:43:31 UTC
+++ content/browser/renderer_host/media/service_video_capture_device_launcher.cc
@@ -25,7 +25,7 @@
 #include "media/base/media_switches.h"
 #endif
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "content/browser/gpu/gpu_data_manager_impl.h"
 #endif
 
@@ -173,7 +173,7 @@ void ServiceVideoCaptureDeviceLauncher::LaunchDeviceAs
   }
 #else
   if (switches::IsVideoCaptureUseGpuMemoryBufferEnabled()) {
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     // On Linux, additionally check whether the NV12 GPU memory buffer is
     // supported.
     if (GpuDataManagerImpl::GetInstance()->IsGpuMemoryBufferNV12Supported())
