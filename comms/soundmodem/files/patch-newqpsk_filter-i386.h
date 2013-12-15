--- newqpsk/filter-i386.h.orig	2012-11-07 05:41:08.000000000 -0500
+++ newqpsk/filter-i386.h	2013-12-14 17:39:18.000000000 -0500
@@ -1,7 +1,7 @@
 #ifndef _FILTER_I386_H
 #define _FILTER_I386_H
 #define __HAVE_ARCH_MAC
-extern inline float mac(const float *a, const float *b, unsigned int size)
+static inline float mac(const float *a, const float *b, unsigned int size)
 {
 	float f;
 	asm volatile (
