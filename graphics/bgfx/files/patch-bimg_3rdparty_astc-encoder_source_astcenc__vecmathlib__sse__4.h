--- bimg/3rdparty/astc-encoder/source/astcenc_vecmathlib_sse_4.h.orig	2024-03-28 05:00:55 UTC
+++ bimg/3rdparty/astc-encoder/source/astcenc_vecmathlib_sse_4.h
@@ -1307,7 +1307,7 @@ ASTCENC_SIMD_INLINE vfloat4 dot3(vfloat4 a, vfloat4 b)
  */
 ASTCENC_SIMD_INLINE int popcount(uint64_t v)
 {
-#if defined(__MINGW32__)
+#if !defined(__x86_64__)
 	return static_cast<int>(__builtin_popcountll(v));
 #else
 	return static_cast<int>(_mm_popcnt_u64(v));
