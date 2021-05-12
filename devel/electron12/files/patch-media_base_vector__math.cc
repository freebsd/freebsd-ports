--- media/base/vector_math.cc.orig	2021-04-14 01:08:51 UTC
+++ media/base/vector_math.cc
@@ -18,7 +18,7 @@
 // better, which is anywhere clang is used.
 // TODO(pcc): Linux currently uses ThinLTO which has broken auto-vectorization
 // in clang, so use our intrinsic version for now. http://crbug.com/738085
-#if !defined(__clang__) || defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if !defined(__clang__) || defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
 #define FMAC_FUNC FMAC_SSE
 #define FMUL_FUNC FMUL_SSE
 #else
