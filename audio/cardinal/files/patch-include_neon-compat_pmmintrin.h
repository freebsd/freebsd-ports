--- include/neon-compat/pmmintrin.h.orig	2023-08-16 16:08:02 UTC
+++ include/neon-compat/pmmintrin.h
@@ -17,7 +17,7 @@
 
 #pragma once
 
-#if defined(__i386__) || defined(__x86_64__) || defined(__EMSCRIPTEN__)
+#if defined(__i386__) || defined(__x86_64__) || defined(__EMSCRIPTEN__) || defined(__powerpc64__)
 # include_next <pmmintrin.h>
 #else
 # include "../sse2neon/sse2neon.h"
