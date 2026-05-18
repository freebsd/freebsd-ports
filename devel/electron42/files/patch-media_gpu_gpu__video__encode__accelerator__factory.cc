--- media/gpu/gpu_video_encode_accelerator_factory.cc.orig	2026-03-13 16:54:03 UTC
+++ media/gpu/gpu_video_encode_accelerator_factory.cc
@@ -67,7 +67,7 @@ std::unique_ptr<VideoEncodeAccelerator> CreateVaapiVEA
 }
 #elif BUILDFLAG(USE_VAAPI)
 std::unique_ptr<VideoEncodeAccelerator> CreateVaapiVEA() {
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   if (!base::FeatureList::IsEnabled(kAcceleratedVideoEncodeLinux)) {
     return nullptr;
   }
