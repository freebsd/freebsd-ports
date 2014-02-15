--- utils/config/tree.ipp.old
+++ utils/config/tree.ipp
@@ -79,13 +79,13 @@ config::tree::lookup(const std::string& dotted_key) const
 {
     const detail::tree_key key = detail::parse_key(dotted_key);
     const detail::base_node* raw_node = _root->lookup_ro(key, 0);
-    try {
-        const LeafType& child = dynamic_cast< const LeafType& >(*raw_node);
-        if (child.is_set())
-            return child.value();
+    const LeafType* child = dynamic_cast< const LeafType* >(raw_node);
+    if (child != NULL) {
+        if (child->is_set())
+            return child->value();
         else
             throw unknown_key_error(key);
-    } catch (const std::bad_cast& unused_error) {
+    } else {
         throw unknown_key_error(key);
     }
 }
@@ -107,13 +107,13 @@ config::tree::lookup_rw(const std::string& dotted_key)
     const detail::tree_key key = detail::parse_key(dotted_key);
     detail::base_node* raw_node = _root->lookup_rw(
         key, 0, detail::new_node< LeafType >);
-    try {
-        LeafType& child = dynamic_cast< LeafType& >(*raw_node);
-        if (child.is_set())
-            return child.value();
+    LeafType* child = dynamic_cast< LeafType* >(raw_node);
+    if (child != NULL) {
+        if (child->is_set())
+            return child->value();
         else
             throw unknown_key_error(key);
-    } catch (const std::bad_cast& unused_error) {
+    } else {
         throw unknown_key_error(key);
     }
 }
@@ -136,10 +136,10 @@ config::tree::set(const std::string& dotted_key,
     const detail::tree_key key = detail::parse_key(dotted_key);
     leaf_node* raw_node = _root->lookup_rw(key, 0,
                                            detail::new_node< LeafType >);
-    try {
-        LeafType& child = dynamic_cast< LeafType& >(*raw_node);
-        child.set(value);
-    } catch (const std::bad_cast& unused_error) {
+    LeafType* child = dynamic_cast< LeafType* >(raw_node);
+    if (child != NULL) {
+        child->set(value);
+    } else {
         throw value_error(F("Invalid value for key '%s'") %
                           detail::flatten_key(key));
     }
