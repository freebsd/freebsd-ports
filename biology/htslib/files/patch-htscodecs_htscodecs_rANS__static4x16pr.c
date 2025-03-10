--- htscodecs/htscodecs/rANS_static4x16pr.c.orig	2024-10-09 21:44:38 UTC
+++ htscodecs/htscodecs/rANS_static4x16pr.c
@@ -1030,7 +1030,7 @@ unsigned char *(*rans_dec_func(int do_simd, int order)
     }
 }
 
-#elif defined(__ARM_NEON) && defined(__aarch64__)
+#elif defined(__ARM_NEON)
 
 #if defined(__linux__) || defined(__FreeBSD__)
 #include <sys/auxv.h>
