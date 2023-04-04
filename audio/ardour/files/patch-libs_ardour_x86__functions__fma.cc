--- libs/ardour/x86_functions_fma.cc.orig	2023-02-21 01:16:53 UTC
+++ libs/ardour/x86_functions_fma.cc
@@ -67,8 +67,8 @@ x86_fma_mix_buffers_with_gain(
 
 		while (nframes >= 16) {
 #if defined(COMPILER_MSVC) || defined(COMPILER_MINGW)
-			_mm_prefetch(((char *)dst + (16 * sizeof(float))), _mm_hint(0));
-			_mm_prefetch(((char *)src + (16 * sizeof(float))), _mm_hint(0));
+			_mm_prefetch(((char *)dst + (16 * sizeof(float))), _MM_HINT_NTA);
+			_mm_prefetch(((char *)src + (16 * sizeof(float))), _MM_HINT_NTA);
 #else
 			__builtin_prefetch(src + (16 * sizeof(float)), 0, 0);
 			__builtin_prefetch(dst + (16 * sizeof(float)), 0, 0);
