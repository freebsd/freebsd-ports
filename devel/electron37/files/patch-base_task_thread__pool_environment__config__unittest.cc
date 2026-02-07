--- base/task/thread_pool/environment_config_unittest.cc.orig	2025-04-22 20:15:27 UTC
+++ base/task/thread_pool/environment_config_unittest.cc
@@ -21,7 +21,7 @@ TEST(ThreadPoolEnvironmentConfig, CanUseBackgroundPrio
             base::FeatureList::IsEnabled(
                 FeatureControllingBackgroundPriorityWorkerThreads()));
 #elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_FUCHSIA) || \
-    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_NACL)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_NACL) || BUILDFLAG(IS_BSD)
   EXPECT_FALSE(CanUseBackgroundThreadTypeForWorkerThread());
 #else
 #error Platform doesn't match any block
@@ -30,7 +30,7 @@ TEST(ThreadPoolEnvironmentConfig, CanUseBackgroundPrio
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_APPLE) || BUILDFLAG(IS_ANDROID)
   EXPECT_TRUE(CanUseUtilityThreadTypeForWorkerThread());
 #elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_FUCHSIA) || \
-    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_NACL)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_NACL) || BUILDFLAG(IS_BSD)
   EXPECT_FALSE(CanUseUtilityThreadTypeForWorkerThread());
 #else
 #error Platform doesn't match any block
