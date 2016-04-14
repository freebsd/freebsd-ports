--- include/mdds/sorted_string_map_def.inl.orig	2015-12-22 00:33:47 UTC
+++ include/mdds/sorted_string_map_def.inl
@@ -65,7 +65,7 @@ sorted_string_map<_ValueT>::sorted_strin
     m_entry_end(m_entries+m_entry_size)
 {
 #ifdef _GLIBCXX_DEBUG
-    assert(std::is_sorted(m_entries, m_entry_end, compare<_ValueT>));
+    assert(std::is_sorted(m_entries, m_entry_end, detail::compare<_ValueT>));
 #endif
 }
 
