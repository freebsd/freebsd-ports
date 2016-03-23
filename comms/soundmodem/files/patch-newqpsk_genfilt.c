--- newqpsk/genfilt.c.orig	2002-08-09 20:01:52 UTC
+++ newqpsk/genfilt.c
@@ -18,7 +18,7 @@ int main(int argc, char **argv)
 	puts("#define _FILTER_I386_H");
 	puts("#define __HAVE_ARCH_MAC");
 
-	puts("extern inline float mac(const float *a, const float *b, unsigned int size)");
+	puts("static inline float mac(const float *a, const float *b, unsigned int size)");
 	puts("{");
 	puts("\tfloat f;");
 	puts("\tasm volatile (");
