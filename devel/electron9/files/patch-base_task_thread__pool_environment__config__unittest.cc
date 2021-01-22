--- base/task/thread_pool/environment_config_unittest.cc.orig	2020-05-26 07:48:14 UTC
+++ base/task/thread_pool/environment_config_unittest.cc
@@ -14,7 +14,7 @@ namespace internal {
 TEST(ThreadPoolEnvironmentConfig, CanUseBackgroundPriorityForWorker) {
 #if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_IOS)
   EXPECT_TRUE(CanUseBackgroundPriorityForWorkerThread());
-#elif defined(OS_LINUX) || defined(OS_ANDROID) || defined(OS_FUCHSIA) || \
+#elif defined(OS_LINUX) || defined(OS_ANDROID) || defined(OS_FUCHSIA) || defined(OS_BSD) || \
     defined(OS_CHROMEOS) || defined(OS_NACL)
   EXPECT_FALSE(CanUseBackgroundPriorityForWorkerThread());
 #else
