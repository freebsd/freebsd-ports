--- src/filter.h.orig	2005-02-27 23:39:24 UTC
+++ src/filter.h
@@ -20,6 +20,8 @@ typedef struct {
 
 	#ifdef ARCH_X86
 	int16 coeffs_i16[NCOEFFS] __attribute__ ((aligned (8)));
+	#elif __x86_64__
+	int16 coeffs_i16[NCOEFFS] __attribute__ ((aligned (8)));
 	#elif ARCH_POWERPC
 	int16 coeffs_i16[NCOEFFS] __attribute__ ((aligned (16)));
 	#endif
