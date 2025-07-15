--- base/threading/platform_thread_unittest.cc.orig	2025-06-30 07:04:30 UTC
+++ base/threading/platform_thread_unittest.cc
@@ -36,7 +36,7 @@
 #include "base/time/time.h"
 #endif
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 #include <pthread.h>
 #include <sys/syscall.h>
 #include <sys/types.h>
@@ -369,7 +369,7 @@ TEST(PlatformThreadTest, CanChangeThreadType) {
 // and hardcodes what we know. Please inform scheduler-dev@chromium.org if this
 // proprerty changes for a given platform.
 TEST(PlatformThreadTest, CanChangeThreadType) {
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   // On Ubuntu, RLIMIT_NICE and RLIMIT_RTPRIO are 0 by default, so we won't be
   // able to increase priority to any level unless we are root (euid == 0).
   bool kCanIncreasePriority = false;
@@ -606,12 +606,16 @@ INSTANTIATE_TEST_SUITE_P(
 
 #endif  // BUILDFLAG(IS_APPLE)
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 
 namespace {
 
 bool IsTidCacheCorrect() {
+#if BUILDFLAG(IS_BSD)
+  return PlatformThread::CurrentId().raw() == reinterpret_cast<int64_t>(pthread_self());
+#else
   return PlatformThread::CurrentId().raw() == syscall(__NR_gettid);
+#endif
 }
 
 void* CheckTidCacheCorrectWrapper(void*) {
