--- include/mdds/mixed_type_matrix_storage_filled_linear.inl.orig	2015-06-11 23:53:55 UTC
+++ include/mdds/mixed_type_matrix_storage_filled_linear.inl
@@ -354,8 +354,8 @@ public:
         }
 
         array_type new_array(new_size, &m_init_elem);
-        size_t min_rows = ::std::min(row, m_rows);
-        size_t min_cols = ::std::min(col, m_cols);
+        size_t min_rows = (::std::min)(row, m_rows);
+        size_t min_cols = (::std::min)(col, m_cols);
         for (size_t i = 0; i < min_rows; ++i)
         {
             for (size_t j = 0; j < min_cols; ++j)
@@ -614,8 +614,8 @@ public:
         }
 
         array_type new_array(new_size, element(0.0));
-        size_t min_rows = ::std::min(row, m_rows);
-        size_t min_cols = ::std::min(col, m_cols);
+        size_t min_rows = (::std::min)(row, m_rows);
+        size_t min_cols = (::std::min)(col, m_cols);
         for (size_t i = 0; i < min_rows; ++i)
         {
             for (size_t j = 0; j < min_cols; ++j)
