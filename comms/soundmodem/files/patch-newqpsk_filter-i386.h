--- newqpsk/filter-i386.h.orig	2015-05-04 17:52:25 UTC
+++ newqpsk/filter-i386.h
@@ -1,7 +1,7 @@
 #ifndef _FILTER_I386_H
 #define _FILTER_I386_H
 #define __HAVE_ARCH_MAC
-extern inline float mac(const float *a, const float *b, unsigned int size)
+static inline float mac(const float *a, const float *b, unsigned int size)
 {
 	float f;
 	asm volatile (
