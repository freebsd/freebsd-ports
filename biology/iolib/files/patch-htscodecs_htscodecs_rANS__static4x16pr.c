--- htscodecs/htscodecs/rANS_static4x16pr.c.orig	2026-03-24 19:05:28 UTC
+++ htscodecs/htscodecs/rANS_static4x16pr.c
@@ -1006,7 +1006,7 @@ unsigned char *(*rans_dec_func(int do_simd, int order)
     }
 }
 
-#elif defined(__ARM_NEON)
+#elif defined(__ARM_NEON) && defined(__aarch64__)
 
 #if defined(__linux__) || defined(__FreeBSD__)
 #include <sys/auxv.h>
