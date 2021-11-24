--- net/nqe/network_quality_estimator_unittest.cc.orig	2021-07-15 19:13:42 UTC
+++ net/nqe/network_quality_estimator_unittest.cc
@@ -2097,9 +2097,9 @@ TEST_F(NetworkQualityEstimatorTest, TestGlobalSocketWa
 // ChromeOS is disabled due to crbug.com/986904
 // TODO(crbug.com/1052397): Revisit once build flag switch of lacros-chrome is
 // complete.
-#if (defined(TCP_INFO) ||                                    \
-     (defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)) || \
-     defined(OS_ANDROID)) &&                                 \
+#if (defined(TCP_INFO) ||                                                       \
+     (defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)) || defined(OS_BSD) || \
+     defined(OS_ANDROID)) &&                                                    \
     !defined(OS_CHROMEOS)
 #define MAYBE_TestTCPSocketRTT TestTCPSocketRTT
 #else
