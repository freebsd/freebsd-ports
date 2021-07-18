--- chromecast/app/cast_main_delegate.cc.orig	2021-04-14 01:08:44 UTC
+++ chromecast/app/cast_main_delegate.cc
@@ -136,7 +136,7 @@ bool CastMainDelegate::BasicStartupComplete(int* exit_
 
 void CastMainDelegate::PreSandboxStartup() {
 #if defined(ARCH_CPU_ARM_FAMILY) && \
-    (defined(OS_ANDROID) || defined(OS_LINUX) || defined(OS_CHROMEOS))
+    (defined(OS_ANDROID) || defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD))
   // Create an instance of the CPU class to parse /proc/cpuinfo and cache the
   // results. This data needs to be cached when file-reading is still allowed,
   // since base::CPU expects to be callable later, when file-reading is no
