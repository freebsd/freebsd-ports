--- media/video/video_encode_accelerator_adapter.cc.orig	2021-07-15 19:13:41 UTC
+++ media/video/video_encode_accelerator_adapter.cc
@@ -67,7 +67,7 @@ VideoEncodeAccelerator::Config SetUpVeaConfig(
   if (is_rgb)
     config.input_format = PIXEL_FORMAT_I420;
 
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
   if (storage_type == VideoFrame::STORAGE_DMABUFS ||
       storage_type == VideoFrame::STORAGE_GPU_MEMORY_BUFFER) {
     if (is_rgb)
@@ -209,7 +209,7 @@ void VideoEncodeAcceleratorAdapter::InitializeInternal
   auto vea_config =
       SetUpVeaConfig(profile_, options_, format, first_frame->storage_type());
 
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
   // Linux/ChromeOS require a special configuration to use dmabuf storage.
   // We need to keep sending frames the same way the first frame was sent.
   // Other platforms will happily mix GpuMemoryBuffer storage with regular
