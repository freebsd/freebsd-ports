--- CalculiX.h.orig	2019-11-25 17:54:53 UTC
+++ CalculiX.h
@@ -17,12 +17,14 @@
 
 #include <pthread.h>
 
-#define Linux 1
+#include <pthread.h>
+
+#define FreeBSD 1
 #define IRIX 2
 #define IRIX64 3
 #define HP 4
 
-#if ARCH == Linux
+#if ARCH == FreeBSD
 #define FORTRAN(A,B) A##_  B
 #elif ARCH == IRIX || ARCH == IRIX64
 #define FORTRAN(A,B) A##_##B
@@ -30,7 +32,7 @@
 #define FORTRAN(A,B) A##B
 #endif
 
-#if ARCH == Linux
+#if ARCH == FreeBSD
 #define CEE(A,B) A##_  B
 #elif ARCH == IRIX || ARCH == IRIX64
 #define CEE(A,B) A##_##B
