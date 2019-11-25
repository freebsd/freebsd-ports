--- content/browser/renderer_host/render_process_host_impl.cc.orig	2019-09-16 09:24:25 UTC
+++ content/browser/renderer_host/render_process_host_impl.cc
@@ -230,7 +230,7 @@
 #include "content/browser/compositor/image_transport_factory.h"
 #endif
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 #include <sys/resource.h>
 #include <sys/time.h>
 #endif
@@ -1244,7 +1244,7 @@ static constexpr size_t kUnknownPlatformProcessLimit =
 // to indicate failure and std::numeric_limits<size_t>::max() to indicate
 // unlimited.
 size_t GetPlatformProcessLimit() {
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   struct rlimit limit;
   if (getrlimit(RLIMIT_NPROC, &limit) != 0)
     return kUnknownPlatformProcessLimit;
@@ -1255,7 +1255,7 @@ size_t GetPlatformProcessLimit() {
 #else
   // TODO(https://crbug.com/104689): Implement on other platforms.
   return kUnknownPlatformProcessLimit;
-#endif  // defined(OS_LINUX)
+#endif  // defined(OS_LINUX) || defined(OS_BSD)
 }
 #endif  // !defined(OS_ANDROID) && !defined(OS_CHROMEOS)
 
@@ -1667,7 +1667,7 @@ bool RenderProcessHostImpl::Init() {
   renderer_prefix =
       browser_command_line.GetSwitchValueNative(switches::kRendererCmdPrefix);
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   int flags = renderer_prefix.empty() ? ChildProcessHost::CHILD_ALLOW_SELF
                                       : ChildProcessHost::CHILD_NORMAL;
 #elif defined(OS_MACOSX)
