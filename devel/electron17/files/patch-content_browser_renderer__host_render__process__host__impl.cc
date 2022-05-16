--- content/browser/renderer_host/render_process_host_impl.cc.orig	2022-05-13 07:19:54 UTC
+++ content/browser/renderer_host/render_process_host_impl.cc
@@ -198,7 +198,7 @@
 #include "third_party/blink/public/mojom/android_font_lookup/android_font_lookup.mojom.h"
 #endif
 
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
 #include <sys/resource.h>
 
 #include "components/services/font/public/mojom/font_service.mojom.h"  // nogncheck
@@ -1218,7 +1218,7 @@ static constexpr size_t kUnknownPlatformProcessLimit =
 // to indicate failure and std::numeric_limits<size_t>::max() to indicate
 // unlimited.
 size_t GetPlatformProcessLimit() {
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
   struct rlimit limit;
   if (getrlimit(RLIMIT_NPROC, &limit) != 0)
     return kUnknownPlatformProcessLimit;
@@ -1305,7 +1305,7 @@ class RenderProcessHostImpl::IOThreadHostImpl : public
         return;
     }
 
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
     if (auto font_receiver = receiver.As<font_service::mojom::FontService>()) {
       ConnectToFontService(std::move(font_receiver));
       return;
@@ -3314,6 +3314,7 @@ void RenderProcessHostImpl::PropagateBrowserCommandLin
     switches::kDisableSpeechAPI,
     switches::kDisableThreadedCompositing,
     switches::kDisableTouchDragDrop,
+    switches::kDisableUnveil,
     switches::kDisableV8IdleTasks,
     switches::kDisableVideoCaptureUseGpuMemoryBuffer,
     switches::kDisableWebGLImageChromium,
