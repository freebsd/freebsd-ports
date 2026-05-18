--- components/viz/service/gl/gpu_service_impl.h.orig	2026-04-28 21:06:17 UTC
+++ components/viz/service/gl/gpu_service_impl.h
@@ -437,7 +437,7 @@ class VIZ_SERVICE_EXPORT GpuServiceImpl
 
   void OnBeginFrameOnIO(const BeginFrameArgs& args);
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   bool IsGMBNV12Supported();
 #endif
 
