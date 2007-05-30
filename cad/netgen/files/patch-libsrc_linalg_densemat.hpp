--- libsrc/linalg/densemat.hpp.orig	Wed Nov 10 14:22:43 2004
+++ libsrc/linalg/densemat.hpp	Tue May 29 18:45:09 2007
@@ -255,6 +255,6 @@
 
 
 
-
+extern void CalcInverse (const DenseMatrix & m1, DenseMatrix & m2);
 
 #endif
