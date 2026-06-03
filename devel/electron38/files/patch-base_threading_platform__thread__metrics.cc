--- base/threading/platform_thread_metrics.cc.orig	2025-08-26 20:49:50 UTC
+++ base/threading/platform_thread_metrics.cc
@@ -26,7 +26,7 @@ PlatformThreadMetrics::CreateForCurrentThread() {
 }
 
 #elif BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_CHROMEOS) || \
-    BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_LINUX)
+    BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 
 // static
 std::unique_ptr<PlatformThreadMetrics>
