--- include/mdds/flat_segment_tree_def.inl.orig	2015-06-11 23:53:55 UTC
+++ include/mdds/flat_segment_tree_def.inl
@@ -46,7 +46,7 @@ flat_segment_tree<_Key, _Value>::flat_se
     // We don't ever use the value of the right leaf node, but we need the
     // value to be always the same, to make it easier to check for
     // equality.
-    m_right_leaf->value_leaf.value = ::std::numeric_limits<value_type>::max();
+    m_right_leaf->value_leaf.value = init_val;
 }
 
 template<typename _Key, typename _Value>
