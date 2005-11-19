--- ccx_1.4/src/CalculiX.h.orig	Sat Aug 13 05:39:08 2005
+++ ccx_1.4/src/CalculiX.h	Mon Oct 10 16:07:52 2005
@@ -26,6 +26,8 @@
 #define FORTRAN(A,B) A##_##B
 #elif ARCH == HP
 #define FORTRAN(A,B) A##B
+#else
+#define FORTRAN(A,B) A##_ B
 #endif
 
 #define NNEW(a,b) (a *)u_calloc((b),sizeof(a))
