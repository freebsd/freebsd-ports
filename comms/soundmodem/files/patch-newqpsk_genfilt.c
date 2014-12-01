--- newqpsk/genfilt.c.orig	2014-12-01 09:43:37.000000000 +0000
+++ newqpsk/genfilt.c	2014-12-01 09:43:45.000000000 +0000
@@ -18,7 +18,7 @@
 	puts("#define _FILTER_I386_H");
 	puts("#define __HAVE_ARCH_MAC");
 
-	puts("extern inline float mac(const float *a, const float *b, unsigned int size)");
+	puts("static inline float mac(const float *a, const float *b, unsigned int size)");
 	puts("{");
 	puts("\tfloat f;");
 	puts("\tasm volatile (");
