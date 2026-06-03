--- content/browser/gpu/gpu_data_manager_impl.cc.orig	2026-05-26 20:44:49 UTC
+++ content/browser/gpu/gpu_data_manager_impl.cc
@@ -427,7 +427,7 @@ void GpuDataManagerImpl::OnDisplayMetricsChanged(
   private_->OnDisplayMetricsChanged(display, changed_metrics);
 }
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 bool GpuDataManagerImpl::IsGpuMemoryBufferNV12Supported() {
   base::AutoLock auto_lock(lock_);
   return private_->IsGpuMemoryBufferNV12Supported();
