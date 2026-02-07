--- src/third_party/mozjs/extract/mozglue/misc/SIMD.cpp.orig	2024-11-07 09:56:02 UTC
+++ src/third_party/mozjs/extract/mozglue/misc/SIMD.cpp
@@ -448,7 +448,7 @@ const char* SIMD::memchr8SSE2(const char* ptr, char va
 // assertion failure. Accordingly, we just don't allow that to happen. We
 // are not particularly concerned about ensuring that newer 32 bit processors
 // get access to the AVX2 functions exposed here.
-#  if defined(MOZILLA_MAY_SUPPORT_AVX2) && defined(__x86_64__)
+#  if 0 && defined(MOZILLA_MAY_SUPPORT_AVX2) && defined(__x86_64__)
 
 bool SupportsAVX2() { return supports_avx2(); }
 
