--- services/video_capture/video_capture_service_impl.h.orig	2023-10-19 19:58:30 UTC
+++ services/video_capture/video_capture_service_impl.h
@@ -24,7 +24,7 @@
 #include "services/video_capture/ash/video_capture_device_factory_ash.h"
 #endif  // BUILDFLAG(IS_CHROMEOS_ASH)
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
 #include "services/viz/public/cpp/gpu/gpu.h"
 #endif  // BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN)
 
@@ -62,7 +62,7 @@ class VideoCaptureServiceImpl : public mojom::VideoCap
 #if BUILDFLAG(IS_WIN)
   void OnGpuInfoUpdate(const CHROME_LUID& luid) override;
 #endif
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
   void SetVizGpu(std::unique_ptr<viz::Gpu> viz_gpu);
 #endif  // BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN)
  private:
@@ -87,7 +87,7 @@ class VideoCaptureServiceImpl : public mojom::VideoCap
       factory_receivers_ash_;
 #endif
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
   class VizGpuContextProvider;
   std::unique_ptr<VizGpuContextProvider> viz_gpu_context_provider_;
   std::unique_ptr<viz::Gpu> viz_gpu_;
