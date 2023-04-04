--- libs/ardour/x86_functions_avx512f.cc.orig	2023-02-21 01:05:04 UTC
+++ libs/ardour/x86_functions_avx512f.cc
@@ -83,7 +83,7 @@ x86_avx512f_compute_peak(const float *src, uint32_t nf
 	}
 
 	while (frames >= 256) {
-		_mm_prefetch(reinterpret_cast<void const *>(src + 256), _mm_hint(0));
+		_mm_prefetch(reinterpret_cast<void const *>(src + 256), _MM_HINT_NTA);
 
 		__m512 x0 = _mm512_load_ps(src + 0);
 		__m512 x1 = _mm512_load_ps(src + 16);
@@ -142,7 +142,7 @@ x86_avx512f_compute_peak(const float *src, uint32_t nf
 	}
 
 	while (frames >= 128) {
-		_mm_prefetch(reinterpret_cast<void const *>(src + 128), _mm_hint(0));
+		_mm_prefetch(reinterpret_cast<void const *>(src + 128), _MM_HINT_NTA);
 
 		__m512 x0 = _mm512_load_ps(src + 0);
 		__m512 x1 = _mm512_load_ps(src + 16);
@@ -176,7 +176,7 @@ x86_avx512f_compute_peak(const float *src, uint32_t nf
 	}
 
 	while (frames >= 64) {
-		_mm_prefetch(reinterpret_cast<void const *>(src + 64), _mm_hint(0));
+		_mm_prefetch(reinterpret_cast<void const *>(src + 64), _MM_HINT_NTA);
 
 		__m512 x0 = _mm512_load_ps(src + 0);
 		__m512 x1 = _mm512_load_ps(src + 16);
@@ -310,7 +310,7 @@ x86_avx512f_find_peaks(const float *src, uint32_t nfra
 	}
 
 	while (frames >= 256) {
-		_mm_prefetch(reinterpret_cast<void const *>(src + 256), _mm_hint(0));
+		_mm_prefetch(reinterpret_cast<void const *>(src + 256), _MM_HINT_NTA);
 
 		__m512 x0 = _mm512_load_ps(src + 0);
 		__m512 x1 = _mm512_load_ps(src + 16);
@@ -371,7 +371,7 @@ x86_avx512f_find_peaks(const float *src, uint32_t nfra
 	}
 
 	while (frames >= 128) {
-		_mm_prefetch(reinterpret_cast<void const *>(src + 128), _mm_hint(0));
+		_mm_prefetch(reinterpret_cast<void const *>(src + 128), _MM_HINT_NTA);
 
 		__m512 x0 = _mm512_load_ps(src + 0);
 		__m512 x1 = _mm512_load_ps(src + 16);
@@ -405,7 +405,7 @@ x86_avx512f_find_peaks(const float *src, uint32_t nfra
 	}
 
 	while (frames >= 64) {
-		_mm_prefetch(reinterpret_cast<void const *>(src + 64), _mm_hint(0));
+		_mm_prefetch(reinterpret_cast<void const *>(src + 64), _MM_HINT_NTA);
 
 		__m512 x0 = _mm512_load_ps(src + 0);
 		__m512 x1 = _mm512_load_ps(src + 16);
@@ -532,7 +532,7 @@ x86_avx512f_apply_gain_to_buffer(float *dst, uint32_t 
 
 	// Process the remaining samples 128 at a time
 	while (frames >= 128) {
-		_mm_prefetch(reinterpret_cast<void const *>(dst + 128), _mm_hint(0));
+		_mm_prefetch(reinterpret_cast<void const *>(dst + 128), _MM_HINT_NTA);
 
 		__m512 x0 = _mm512_load_ps(dst + 0);
 		__m512 x1 = _mm512_load_ps(dst + 16);
@@ -679,8 +679,8 @@ x86_avx512f_mix_buffers_with_gain(float *dst, const fl
 
 	// Process the remaining samples 128 at a time
 	while (frames >= 128) {
-		_mm_prefetch(reinterpret_cast<void const *>(src + 128), _mm_hint(0));
-		_mm_prefetch(reinterpret_cast<void const *>(dst + 128), _mm_hint(0));
+		_mm_prefetch(reinterpret_cast<void const *>(src + 128), _MM_HINT_NTA);
+		_mm_prefetch(reinterpret_cast<void const *>(dst + 128), _MM_HINT_NTA);
 
 		__m512 x0 = _mm512_load_ps(src + 0);
 		__m512 x1 = _mm512_load_ps(src + 16);
@@ -836,8 +836,8 @@ x86_avx512f_mix_buffers_no_gain(float *dst, const floa
 
 	// Process the remaining samples 128 at a time
 	while (frames >= 128) {
-		_mm_prefetch(reinterpret_cast<void const *>(src + 128), _mm_hint(0));
-		_mm_prefetch(reinterpret_cast<void const *>(dst + 128), _mm_hint(0));
+		_mm_prefetch(reinterpret_cast<void const *>(src + 128), _MM_HINT_NTA);
+		_mm_prefetch(reinterpret_cast<void const *>(dst + 128), _MM_HINT_NTA);
 
 		__m512 x0 = _mm512_load_ps(src + 0);
 		__m512 x1 = _mm512_load_ps(src + 16);
@@ -987,8 +987,8 @@ x86_avx512f_copy_vector(float *dst, const float *src, 
 
 	// Process 256 samples at a time
 	while (frames >= 256) {
-		_mm_prefetch(reinterpret_cast<void const *>(src + 256), _mm_hint(0));
-		_mm_prefetch(reinterpret_cast<void const *>(dst + 256), _mm_hint(0));
+		_mm_prefetch(reinterpret_cast<void const *>(src + 256), _MM_HINT_NTA);
+		_mm_prefetch(reinterpret_cast<void const *>(dst + 256), _MM_HINT_NTA);
 
 		__m512 x0 = _mm512_load_ps(src + 0);
 		__m512 x1 = _mm512_load_ps(src + 16);
@@ -1033,8 +1033,8 @@ x86_avx512f_copy_vector(float *dst, const float *src, 
 
 	// Process remaining samples 64 at a time
 	while (frames >= 64) {
-		_mm_prefetch(reinterpret_cast<void const *>(src + 64), _mm_hint(0));
-		_mm_prefetch(reinterpret_cast<void const *>(dst + 64), _mm_hint(0));
+		_mm_prefetch(reinterpret_cast<void const *>(src + 64), _MM_HINT_NTA);
+		_mm_prefetch(reinterpret_cast<void const *>(dst + 64), _MM_HINT_NTA);
 
 		__m512 x0 = _mm512_load_ps(src + 0);
 		__m512 x1 = _mm512_load_ps(src + 16);
