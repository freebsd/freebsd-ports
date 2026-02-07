--- base/threading/platform_thread_metrics.cc.orig	2025-10-21 20:19:54 UTC
+++ base/threading/platform_thread_metrics.cc
@@ -55,7 +55,7 @@ PlatformThreadMetrics::CreateForCurrentThread() {
 }
 
 #elif BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_CHROMEOS) || \
-    BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_LINUX)
+    BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 
 // static
 std::unique_ptr<PlatformThreadMetrics>
