--- libs/ardour/sse_functions_avx_linux.cc.orig	2023-02-21 01:17:58 UTC
+++ libs/ardour/sse_functions_avx_linux.cc
@@ -106,7 +106,7 @@ x86_sse_avx_compute_peak(const float *src, uint32_t nf
 	while (nframes >= 32)
 	{
 #ifdef _WIN32
-		_mm_prefetch(reinterpret_cast<char const *>(src + 32), _mm_hint(0));
+		_mm_prefetch(reinterpret_cast<char const *>(src + 32), _MM_HINT_NTA);
 #else
 		__builtin_prefetch(reinterpret_cast<void const *>(src + 32), 0, 0);
 #endif
@@ -196,7 +196,7 @@ x86_sse_avx_find_peaks(const float *src, uint32_t nfra
 	while (nframes >= 32)
 	{
 #ifdef _WIN32
-		_mm_prefetch(reinterpret_cast<char const *>(src + 32), _mm_hint(0));
+		_mm_prefetch(reinterpret_cast<char const *>(src + 32), _MM_HINT_NTA);
 #else
 		__builtin_prefetch(reinterpret_cast<void const *>(src + 32), 0, 0);
 #endif
@@ -278,7 +278,7 @@ x86_sse_avx_apply_gain_to_buffer(float *dst, uint32_t 
 	while (frames >= 16)
 	{
 #if defined(COMPILER_MSVC) || defined(COMPILER_MINGW)
-		_mm_prefetch(((char *)dst + (16 * sizeof(float))), _mm_hint(0));
+		_mm_prefetch(((char *)dst + (16 * sizeof(float))), _MM_HINT_NTA);
 #else
 		__builtin_prefetch(reinterpret_cast<void const *>(dst + 16), 0, 0);
 #endif
@@ -410,8 +410,8 @@ x86_sse_avx_mix_buffers_with_gain_unaligned(float *dst
 	while (nframes >= 16)
 	{
 #if defined(COMPILER_MSVC) || defined(COMPILER_MINGW)
-		_mm_prefetch(((char *)dst + (16 * sizeof(float))), _mm_hint(0));
-		_mm_prefetch(((char *)src + (16 * sizeof(float))), _mm_hint(0));
+		_mm_prefetch(((char *)dst + (16 * sizeof(float))), _MM_HINT_NTA);
+		_mm_prefetch(((char *)src + (16 * sizeof(float))), _MM_HINT_NTA);
 #else
 		__builtin_prefetch(reinterpret_cast<void const *>(src + 16), 0, 0);
 		__builtin_prefetch(reinterpret_cast<void const *>(dst + 16), 0, 0);
@@ -503,8 +503,8 @@ x86_sse_avx_mix_buffers_with_gain_aligned(float *dst, 
 	while (nframes >= 16)
 	{
 #if defined(COMPILER_MSVC) || defined(COMPILER_MINGW)
-		_mm_prefetch(((char *)dst + (16 * sizeof(float))), _mm_hint(0));
-		_mm_prefetch(((char *)src + (16 * sizeof(float))), _mm_hint(0));
+		_mm_prefetch(((char *)dst + (16 * sizeof(float))), _MM_HINT_NTA);
+		_mm_prefetch(((char *)src + (16 * sizeof(float))), _MM_HINT_NTA);
 #else
 		__builtin_prefetch(reinterpret_cast<void const *>(src + 16), 0, 0);
 		__builtin_prefetch(reinterpret_cast<void const *>(dst + 16), 0, 0);
@@ -592,8 +592,8 @@ x86_sse_avx_mix_buffers_no_gain_unaligned(float *dst, 
 	while (nframes >= 16)
 	{
 #if defined(COMPILER_MSVC) || defined(COMPILER_MINGW)
-		_mm_prefetch(((char *)dst + (16 * sizeof(float))), _mm_hint(0));
-		_mm_prefetch(((char *)src + (16 * sizeof(float))), _mm_hint(0));
+		_mm_prefetch(((char *)dst + (16 * sizeof(float))), _MM_HINT_NTA);
+		_mm_prefetch(((char *)src + (16 * sizeof(float))), _MM_HINT_NTA);
 #else
 		__builtin_prefetch(reinterpret_cast<void const *>(src + 16), 0, 0);
 		__builtin_prefetch(reinterpret_cast<void const *>(dst + 16), 0, 0);
@@ -674,8 +674,8 @@ x86_sse_avx_mix_buffers_no_gain_aligned(float *dst, co
 	while (nframes >= 32)
 	{
 #if defined(COMPILER_MSVC) || defined(COMPILER_MINGW)
-		_mm_prefetch(((char *)dst + (32 * sizeof(float))), _mm_hint(0));
-		_mm_prefetch(((char *)src + (32 * sizeof(float))), _mm_hint(0));
+		_mm_prefetch(((char *)dst + (32 * sizeof(float))), _MM_HINT_NTA);
+		_mm_prefetch(((char *)src + (32 * sizeof(float))), _MM_HINT_NTA);
 #else
 		__builtin_prefetch(reinterpret_cast<void const *>(src + 32), 0, 0);
 		__builtin_prefetch(reinterpret_cast<void const *>(dst + 32), 0, 0);
@@ -717,8 +717,8 @@ x86_sse_avx_mix_buffers_no_gain_aligned(float *dst, co
 	while (nframes >= 16)
 	{
 #if defined(COMPILER_MSVC) || defined(COMPILER_MINGW)
-		_mm_prefetch(((char *)dst + (16 * sizeof(float))), _mm_hint(0));
-		_mm_prefetch(((char *)src + (16 * sizeof(float))), _mm_hint(0));
+		_mm_prefetch(((char *)dst + (16 * sizeof(float))), _MM_HINT_NTA);
+		_mm_prefetch(((char *)src + (16 * sizeof(float))), _MM_HINT_NTA);
 #else
 		__builtin_prefetch(reinterpret_cast<void const *>(src + 16), 0, 0);
 		__builtin_prefetch(reinterpret_cast<void const *>(dst + 16), 0, 0);
