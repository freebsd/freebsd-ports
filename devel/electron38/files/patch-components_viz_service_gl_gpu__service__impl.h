--- components/viz/service/gl/gpu_service_impl.h.orig	2025-08-26 20:49:50 UTC
+++ components/viz/service/gl/gpu_service_impl.h
@@ -450,7 +450,7 @@ class VIZ_SERVICE_EXPORT GpuServiceImpl
 
   void OnBeginFrameOnIO(const BeginFrameArgs& args);
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   bool IsGMBNV12Supported();
 #endif
 
