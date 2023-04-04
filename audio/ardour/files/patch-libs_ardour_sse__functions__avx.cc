--- libs/ardour/sse_functions_avx.cc.orig	2023-02-21 01:18:30 UTC
+++ libs/ardour/sse_functions_avx.cc
@@ -47,7 +47,7 @@ x86_sse_avx_find_peaks(const float* buf, uint32_t nfra
 		// load each 64 bytes into cash before processing
         while (nframes >= 16) {
 #if defined(COMPILER_MSVC) || defined(COMPILER_MINGW)
-				_mm_prefetch(((char*)buf+64), _mm_hint(0) );
+				_mm_prefetch(((char*)buf+64), _MM_HINT_NTA );
 #else
                 __builtin_prefetch(buf+64,0,0);
 #endif
