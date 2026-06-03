--- source/blender/blenlib/intern/math_half.cc.orig	2026-05-16 23:53:32 UTC
+++ source/blender/blenlib/intern/math_half.cc
@@ -271,7 +271,7 @@ void blender::math::float_to_half_array(const float *s
   }
 }
 
-#ifndef __SSE4_1__
+#if !defined(__SSE4_1__) && (defined(__x86_64__) || defined(_M_X64))
 static inline __m128i srai_epi8_sse2(__m128i x, int imm)
 {
     // Sign-extend bytes to 16-bit
