--- ccx_1.3/src/CalculiX.h.orig	Mon Mar  3 00:35:58 2003
+++ ccx_1.3/src/CalculiX.h	Mon May  5 21:15:50 2003
@@ -24,6 +24,8 @@
 #define FORTRAN(A,B) A##_##B
 #elif ARCH == HP
 #define FORTRAN(A,B) A##B
+#else
+#define FORTRAN(A,B) A##_ B
 #endif
 
 #define NNEW(a,b) (a *)u_calloc((b),sizeof(a))
