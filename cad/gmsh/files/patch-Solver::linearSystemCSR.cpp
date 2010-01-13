--- Solver/linearSystemCSR.cpp.orig	2010-01-02 16:10:27.000000000 -0600
+++ Solver/linearSystemCSR.cpp	2010-01-02 16:10:40.000000000 -0600
@@ -245,7 +245,7 @@
 }
 
 template <class scalar>
-static void sortColumns(int NbLines, 
+void sortColumns(int NbLines, 
                         int nnz, 
                         INDEX_TYPE *ptr, 
                         INDEX_TYPE *jptr, 
