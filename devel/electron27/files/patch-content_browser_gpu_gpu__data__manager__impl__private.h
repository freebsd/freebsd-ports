--- content/browser/gpu/gpu_data_manager_impl_private.h.orig	2023-10-25 09:13:44 UTC
+++ content/browser/gpu/gpu_data_manager_impl_private.h
@@ -152,7 +152,7 @@ class CONTENT_EXPORT GpuDataManagerImplPrivate {
   void OnDisplayMetricsChanged(const display::Display& display,
                                uint32_t changed_metrics);
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   bool IsGpuMemoryBufferNV12Supported();
   void SetGpuMemoryBufferNV12Supported(bool supported);
 #endif  // BUILDFLAG(IS_LINUX)
@@ -307,7 +307,7 @@ class CONTENT_EXPORT GpuDataManagerImplPrivate {
   bool application_is_visible_ = true;
 
   bool disable_gpu_compositing_ = false;
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   bool is_gpu_memory_buffer_NV12_supported_ = false;
 #endif  // BUILDFLAG(IS_LINUX)
 };
