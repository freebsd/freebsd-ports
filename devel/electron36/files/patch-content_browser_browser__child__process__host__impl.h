--- content/browser/browser_child_process_host_impl.h.orig	2025-03-24 20:50:14 UTC
+++ content/browser/browser_child_process_host_impl.h
@@ -36,7 +36,7 @@
 #include "base/win/object_watcher.h"
 #endif
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 #include "content/browser/child_thread_type_switcher_linux.h"
 #endif  // BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
 
@@ -287,7 +287,7 @@ class BrowserChildProcessHostImpl
   std::unique_ptr<tracing::SystemTracingService> system_tracing_service_;
 #endif
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   ChildThreadTypeSwitcher child_thread_type_switcher_;
 #endif  // BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
 
