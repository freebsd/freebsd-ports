Eigen::DynamicSparseMatrix lived in unsupported/ and was removed in Eigen 5.
Eigen::SparseMatrix::coeffRef() inserts missing entries just like the dynamic
variant did, so this keeps the same behaviour while building against both
math/eigen3 and math/eigen5.

--- projects/cgmesh/libigl/include/igl/diag.cpp.orig	2022-09-08 08:37:09 UTC
+++ projects/cgmesh/libigl/include/igl/diag.cpp
@@ -72,7 +72,7 @@
   Eigen::SparseMatrix<T>& X)
 {
   // clear and resize output
-  Eigen::DynamicSparseMatrix<T, Eigen::RowMajor> dyn_X(V.size(),V.size());
+  Eigen::SparseMatrix<T, Eigen::RowMajor> dyn_X(V.size(),V.size());
   dyn_X.reserve(V.size());
   // loop over non-zeros
   for(typename Eigen::SparseVector<T>::InnerIterator it(V); it; ++it)
@@ -89,7 +89,7 @@
 {
   assert(V.rows() == 1 || V.cols() == 1);
   // clear and resize output
-  Eigen::DynamicSparseMatrix<T, Eigen::RowMajor> dyn_X(V.size(),V.size());
+  Eigen::SparseMatrix<T, Eigen::RowMajor> dyn_X(V.size(),V.size());
   dyn_X.reserve(V.size());
   // loop over non-zeros
   for(int i = 0;i<V.size();i++)
