--- ccx_2.1/src/CalculiX.h.orig	Sun Feb 19 22:25:48 2006
+++ ccx_2.1/src/CalculiX.h	Sun Feb 19 22:27:54 2006
@@ -26,6 +26,8 @@
 #define FORTRAN(A,B) A##_##B
 #elif ARCH == HP
 #define FORTRAN(A,B) A##B
+#else
+#define FORTRAN(A,B) A##_ B
 #endif
 
 #define NNEW(a,b) (a *)u_calloc((b),sizeof(a))
