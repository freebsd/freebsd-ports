--- src/OR_Matrix_inlines.hh.orig	2016-02-11 12:31:26 UTC
+++ src/OR_Matrix_inlines.hh
@@ -97,7 +97,7 @@ OR_Matrix<T>::Pseudo_Row<U>::Pseudo_Row(const Pseudo_R
 
 template <typename T>
 template <typename U>
-inline OR_Matrix<T>::Pseudo_Row<U>&
+inline typename OR_Matrix<T>::template Pseudo_Row<U>&
 OR_Matrix<T>::Pseudo_Row<U>::operator=(const Pseudo_Row& y) {
   first = y.first;
 #if PPL_OR_MATRIX_EXTRA_DEBUG
