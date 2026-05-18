--- content/browser/renderer_host/render_process_host_impl.cc.orig	2026-05-12 08:53:52 UTC
+++ content/browser/renderer_host/render_process_host_impl.cc
@@ -225,7 +225,7 @@
 #include "third_party/blink/public/mojom/android_font_lookup/android_font_lookup.mojom.h"
 #endif
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 #include <sys/resource.h>
 
 #include "components/services/font/public/mojom/font_service.mojom.h"  // nogncheck
@@ -1143,7 +1143,7 @@ size_t GetPlatformProcessLimit() {
 // to indicate failure and std::numeric_limits<size_t>::max() to indicate
 // unlimited.
 size_t GetPlatformProcessLimit() {
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   struct rlimit limit;
   if (getrlimit(RLIMIT_NPROC, &limit) != 0)
     return kUnknownPlatformProcessLimit;
@@ -1403,7 +1403,7 @@ void RenderProcessHostImpl::IOThreadHostImpl::SetPid(
 
 void RenderProcessHostImpl::IOThreadHostImpl::SetPid(
     base::ProcessId child_pid) {
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   child_thread_type_switcher_.SetPid(child_pid);
 #endif  // BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
 }
@@ -3690,7 +3690,7 @@ void RenderProcessHostImpl::AppendRendererCommandLine(
             base::TimeTicks::UnixEpoch().since_origin().InMicroseconds()));
   }
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // Append `kDisableVideoCaptureUseGpuMemoryBuffer` flag if there is no support
   // for NV12 GPU memory buffer.
   if (switches::IsVideoCaptureUseGpuMemoryBufferEnabled() &&
@@ -3745,6 +3745,7 @@ void RenderProcessHostImpl::PropagateBrowserCommandLin
       switches::kDisableSkiaRuntimeOpts,
       switches::kDisableSpeechAPI,
       switches::kDisableThreadedCompositing,
+      switches::kDisableUnveil,
       switches::kDisableV8IdleTasks,
       switches::kDisableVideoCaptureUseGpuMemoryBuffer,
       switches::kDomAutomationController,
@@ -5672,7 +5673,7 @@ uint64_t RenderProcessHostImpl::GetPrivateMemoryFootpr
   // - Win: https://crbug.com/707022 .
   uint64_t total_size = 0;
 #if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID) || \
-    BUILDFLAG(IS_FUCHSIA)
+    BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_BSD)
   total_size = dump->platform_private_footprint->rss_anon_bytes +
                dump->platform_private_footprint->vm_swap_bytes;
 #elif BUILDFLAG(IS_APPLE)
