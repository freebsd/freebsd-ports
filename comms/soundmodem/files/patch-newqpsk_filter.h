--- newqpsk/filter.h.orig	2002-08-09 15:01:52.000000000 -0500
+++ newqpsk/filter.h	2013-12-14 17:39:02.000000000 -0500
@@ -12,7 +12,7 @@
 /* ---------------------------------------------------------------------- */
 
 #ifndef __HAVE_ARCH_MAC
-extern inline float mac(const float *a, const float *b, unsigned int size)
+static inline float mac(const float *a, const float *b, unsigned int size)
 {
 	float sum = 0;
 	unsigned int i;
