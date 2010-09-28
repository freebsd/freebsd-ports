--- ./src/filter.h.orig	2010-09-28 11:22:11.000000000 +0200
+++ ./src/filter.h	2010-09-28 11:22:33.000000000 +0200
@@ -20,6 +20,8 @@
 
 	#ifdef ARCH_X86
 	int16 coeffs_i16[NCOEFFS] __attribute__ ((aligned (8)));
+	#elif __x86_64__
+	int16 coeffs_i16[NCOEFFS] __attribute__ ((aligned (8)));
 	#elif ARCH_POWERPC
 	int16 coeffs_i16[NCOEFFS] __attribute__ ((aligned (16)));
 	#endif
