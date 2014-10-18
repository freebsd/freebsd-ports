http://www.pcc.me.uk/pipermail/libclc-dev/2014-October/000732.html

--- generic/include/clc/clctypes.h.orig	2014-10-18 16:18:10.913664139 +0200
+++ generic/include/clc/clctypes.h	2014-10-18 16:21:06.837903054 +0200
@@ -1,12 +1,13 @@
 /* 6.1.1 Built-in Scalar Data Types */
 
-#include <stddef.h>
-
 typedef unsigned char uchar;
 typedef unsigned short ushort;
 typedef unsigned int uint;
 typedef unsigned long ulong;
 
+typedef __SIZE_TYPE__ size_t;
+typedef __PTRDIFF_TYPE__ ptrdiff_t;
+
 #define __stdint_join3(a,b,c) a ## b ## c
 
 #define  __intn_t(n) __stdint_join3(__INT, n, _TYPE__)
@@ -84,3 +85,5 @@
 typedef __attribute__((ext_vector_type(8))) double double8;
 typedef __attribute__((ext_vector_type(16))) double double16;
 #endif
+
+#define NULL ((void *)0)
