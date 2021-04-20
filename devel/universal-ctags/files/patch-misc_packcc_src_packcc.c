--- misc/packcc/src/packcc.c.orig	2021-04-16 22:31:22 UTC
+++ misc/packcc/src/packcc.c
@@ -910,7 +910,7 @@ static size_t populate_bits(size_t x) {
     x |= x >>  4;
     x |= x >>  8;
     x |= x >> 16;
-#ifndef _M_IX86 /* not Windows for x86 (32-bit) */
+#if (defined __SIZEOF_SIZE_T__ && __SIZEOF_SIZE_T__ == 8)
     x |= x >> 32;
 #endif
     return x;
