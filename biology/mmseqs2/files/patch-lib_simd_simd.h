--- lib/simd/simd.h.orig	2025-01-18 10:33:59 UTC
+++ lib/simd/simd.h
@@ -337,14 +337,14 @@ inline uint16_t simd_hmax16_sse(const __m128i buffer) 
 inline uint16_t simd_hmax16_sse(const __m128i buffer) {
     __m128i tmp1 = _mm_subs_epu16(_mm_set1_epi16((short)65535), buffer);
     __m128i tmp3 = _mm_minpos_epu16(tmp1);
-    return (65535 - _mm_cvtsi128_si32(tmp3));
+    return (65535 - _mm_extract_epi16(tmp3, 0));
 }
 
 inline uint8_t simd_hmax8_sse(const __m128i buffer) {
     __m128i tmp1 = _mm_subs_epu8(_mm_set1_epi8((char)255), buffer);
     __m128i tmp2 = _mm_min_epu8(tmp1, _mm_srli_epi16(tmp1, 8));
     __m128i tmp3 = _mm_minpos_epu16(tmp2);
-    return (int8_t)(255 -(int8_t) _mm_cvtsi128_si32(tmp3));
+    return (int8_t)(255 -(int8_t) _mm_extract_epi16(tmp3, 0));
 }
 
 // see https://stackoverflow.com/questions/6996764/fastest-way-to-do-horizontal-sse-vector-sum-or-other-reduction
