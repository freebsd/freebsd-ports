Eigen::DynamicSparseMatrix lived in unsupported/ and was removed in Eigen 5.
Eigen::SparseMatrix::coeffRef() inserts missing entries just like the dynamic
variant did, so this keeps the same behaviour while building against both
math/eigen3 and math/eigen5.

--- projects/cgmesh/libigl/include/igl/slice_into.cpp.orig	2022-09-08 08:37:09 UTC
+++ projects/cgmesh/libigl/include/igl/slice_into.cpp
@@ -34,7 +34,7 @@
 #endif
 
   // create temporary dynamic sparse matrix
-  Eigen::DynamicSparseMatrix<T, Eigen::RowMajor> dyn_Y(Y);
+  Eigen::SparseMatrix<T, Eigen::RowMajor> dyn_Y(Y);
   // Iterate over outside
   for(int k=0; k<X.outerSize(); ++k)
   {
