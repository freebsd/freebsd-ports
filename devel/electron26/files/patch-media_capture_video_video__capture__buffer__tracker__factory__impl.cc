--- media/capture/video/video_capture_buffer_tracker_factory_impl.cc.orig	2023-08-10 01:48:46 UTC
+++ media/capture/video/video_capture_buffer_tracker_factory_impl.cc
@@ -18,7 +18,7 @@
 #include "media/capture/video/mac/gpu_memory_buffer_tracker_mac.h"
 #endif
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "media/capture/video/linux/v4l2_gpu_memory_buffer_tracker.h"
 #endif
 
@@ -33,7 +33,7 @@ VideoCaptureBufferTrackerFactoryImpl::CreateTracker(
       return std::make_unique<GpuMemoryBufferTracker>();
 #elif BUILDFLAG(IS_MAC)
       return std::make_unique<GpuMemoryBufferTrackerMac>();
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
       return std::make_unique<V4L2GpuMemoryBufferTracker>();
 #else
       return nullptr;
