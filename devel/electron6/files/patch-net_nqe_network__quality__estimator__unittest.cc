--- net/nqe/network_quality_estimator_unittest.cc.orig	2019-09-10 11:14:10 UTC
+++ net/nqe/network_quality_estimator_unittest.cc
@@ -2039,7 +2039,7 @@ TEST_F(NetworkQualityEstimatorTest, TestGlobalSocketWa
 
 // TestTCPSocketRTT requires kernel support for tcp_info struct, and so it is
 // enabled only on certain platforms.
-#if defined(TCP_INFO) || defined(OS_LINUX) || defined(OS_ANDROID)
+#if defined(TCP_INFO) || defined(OS_LINUX) || defined(OS_ANDROID) || defined(OS_BSD)
 #define MAYBE_TestTCPSocketRTT TestTCPSocketRTT
 #else
 #define MAYBE_TestTCPSocketRTT DISABLED_TestTCPSocketRTT
