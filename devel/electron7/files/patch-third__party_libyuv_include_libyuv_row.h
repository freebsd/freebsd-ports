--- third_party/libyuv/include/libyuv/row.h.orig	2019-12-12 12:44:25 UTC
+++ third_party/libyuv/include/libyuv/row.h
@@ -157,10 +157,14 @@ extern "C" {
 #define HAS_ARGBSHADEROW_SSE2
 #define HAS_ARGBSUBTRACTROW_SSE2
 #define HAS_ARGBUNATTENUATEROW_SSE2
+#if !(defined(__i386__) && defined(__GNUC__))
 #define HAS_BLENDPLANEROW_SSSE3
+#endif
 #define HAS_COMPUTECUMULATIVESUMROW_SSE2
 #define HAS_CUMULATIVESUMTOAVERAGEROW_SSE2
+#if !(defined(__i386__) && defined(__GNUC__))
 #define HAS_INTERPOLATEROW_SSSE3
+#endif
 #define HAS_RGBCOLORTABLEROW_X86
 #define HAS_SOBELROW_SSE2
 #define HAS_SOBELTOPLANEROW_SSE2
@@ -206,7 +210,9 @@ extern "C" {
 #define HAS_I422TORGB565ROW_AVX2
 #define HAS_I422TORGBAROW_AVX2
 #define HAS_I444TOARGBROW_AVX2
+#if !(defined(__i386__) && defined(__GNUC__))
 #define HAS_INTERPOLATEROW_AVX2
+#endif
 #define HAS_J422TOARGBROW_AVX2
 #define HAS_MERGEUVROW_AVX2
 #define HAS_MIRRORROW_AVX2
@@ -231,7 +237,9 @@ extern "C" {
 #define HAS_ARGBMULTIPLYROW_AVX2
 #define HAS_ARGBSUBTRACTROW_AVX2
 #define HAS_ARGBUNATTENUATEROW_AVX2
+#if !(defined(__i386__) && defined(__GNUC__))
 #define HAS_BLENDPLANEROW_AVX2
+#endif
 
 #if defined(__x86_64__) || !defined(__pic__) || defined(__clang__) || \
     defined(_MSC_VER)
