--- htscodecs/htscodecs/rANS_static32x16pr.h.orig	2026-03-24 19:00:02 UTC
+++ htscodecs/htscodecs/rANS_static32x16pr.h
@@ -146,7 +146,7 @@ unsigned char *rans_uncompress_O1_32x16_avx512(unsigne
 
 //----------------------------------------------------------------------
 // Arm Neon implementation
-#ifdef __ARM_NEON
+#if defined(__ARM_NEON) && defined(__aarch64__)
 unsigned char *rans_compress_O0_32x16_neon(unsigned char *in,
                                            unsigned int in_size,
                                            unsigned char *out,
