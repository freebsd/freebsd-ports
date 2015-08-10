--- include/mdds/mixed_type_matrix_def.inl.orig	2015-06-11 23:53:55 UTC
+++ include/mdds/mixed_type_matrix_def.inl
@@ -220,8 +220,8 @@ void mixed_type_matrix<_String,_Flag>::a
         // assignment to self.
         return;
 
-    size_t row_count = ::std::min(mp_storage->rows(), r.mp_storage->rows());
-    size_t col_count = ::std::min(mp_storage->cols(), r.mp_storage->cols());
+    size_t row_count = (::std::min)(mp_storage->rows(), r.mp_storage->rows());
+    size_t col_count = (::std::min)(mp_storage->cols(), r.mp_storage->cols());
     for (size_t i = 0; i < row_count; ++i)
         for (size_t j = 0; j < col_count; ++j)
             mp_storage->get_element(i, j) = r.mp_storage->get_element(i, j);
