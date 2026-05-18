--- media/video/video_encode_accelerator_adapter.cc.orig	2026-04-28 21:06:17 UTC
+++ media/video/video_encode_accelerator_adapter.cc
@@ -503,7 +503,7 @@ void VideoEncodeAcceleratorAdapter::InitializeOnAccele
 #endif  // BUILDFLAG(USE_PROPRIETARY_CODECS)
 
   auto storage_type = VideoEncodeAccelerator::Config::StorageType::kShmem;
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   // Linux/ChromeOS require a special configuration to use dmabuf storage.
   // We need to keep sending frames with the same storage type.
   // Other platforms will happily mix GpuMemoryBuffer storage with shared-mem
