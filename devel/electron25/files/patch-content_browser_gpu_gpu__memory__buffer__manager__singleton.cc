--- content/browser/gpu/gpu_memory_buffer_manager_singleton.cc.orig	2023-05-25 00:41:54 UTC
+++ content/browser/gpu/gpu_memory_buffer_manager_singleton.cc
@@ -53,7 +53,7 @@ scoped_refptr<base::SingleThreadTaskRunner> GetTaskRun
 #endif
 }
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 bool IsGpuMemoryBufferNV12Supported() {
   static bool is_computed = false;
   static bool supported = false;
@@ -116,7 +116,7 @@ void GpuMemoryBufferManagerSingleton::OnGpuExtraInfoUp
     SetNativeConfigurations(std::move(configs));
   }
 #endif
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // Dynamic check whether the NV12 format is supported as it may be
   // inconsistent between the system GBM (Generic Buffer Management) and
   // chromium miniGBM.
