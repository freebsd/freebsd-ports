--- utils/config/tree.cpp.old
+++ utils/config/tree.cpp
@@ -109,11 +109,10 @@ config::tree::is_set(const std::string& dotted_key) const
     const detail::tree_key key = detail::parse_key(dotted_key);
     try {
         const detail::base_node* raw_node = _root->lookup_ro(key, 0);
-        try {
-            const leaf_node& child = dynamic_cast< const leaf_node& >(
-                *raw_node);
-            return child.is_set();
-        } catch (const std::bad_cast& unused_error) {
+        const leaf_node* child = dynamic_cast< const leaf_node* >(raw_node);
+        if (child != NULL) {
+            return child->is_set();
+        } else {
             return false;
         }
     } catch (const unknown_key_error& unused_error) {
@@ -134,10 +133,10 @@ config::tree::push_lua(const std::string& dotted_key, lutok::state& state) const
 {
     const detail::tree_key key = detail::parse_key(dotted_key);
     const detail::base_node* raw_node = _root->lookup_ro(key, 0);
-    try {
-        const leaf_node& child = dynamic_cast< const leaf_node& >(*raw_node);
-        child.push_lua(state);
-    } catch (const std::bad_cast& unused_error) {
+    const leaf_node* child = dynamic_cast< const leaf_node* >(raw_node);
+    if (child != NULL) {
+        child->push_lua(state);
+    } else {
         throw unknown_key_error(key);
     }
 }
@@ -159,10 +158,10 @@ config::tree::set_lua(const std::string& dotted_key, lutok::state& state,
     const detail::tree_key key = detail::parse_key(dotted_key);
     detail::base_node* raw_node = _root->lookup_rw(
         key, 0, detail::new_node< string_node >);
-    try {
-        leaf_node& child = dynamic_cast< leaf_node& >(*raw_node);
-        child.set_lua(state, value_index);
-    } catch (const std::bad_cast& unused_error) {
+    leaf_node* child = dynamic_cast< leaf_node* >(raw_node);
+    if (child != NULL) {
+        child->set_lua(state, value_index);
+    } else {
         throw value_error(F("Invalid value for key '%s'") %
                           detail::flatten_key(key));
     }
@@ -182,10 +181,10 @@ config::tree::lookup_string(const std::string& dotted_key) const
 {
     const detail::tree_key key = detail::parse_key(dotted_key);
     const detail::base_node* raw_node = _root->lookup_ro(key, 0);
-    try {
-        const leaf_node& child = dynamic_cast< const leaf_node& >(*raw_node);
-        return child.to_string();
-    } catch (const std::bad_cast& unused_error) {
+    const leaf_node* child = dynamic_cast< const leaf_node* >(raw_node);
+    if (child != NULL) {
+        return child->to_string();
+    } else {
         throw unknown_key_error(key);
     }
 }
@@ -210,10 +209,10 @@ config::tree::set_string(const std::string& dotted_key,
     const detail::tree_key key = detail::parse_key(dotted_key);
     detail::base_node* raw_node = _root->lookup_rw(
         key, 0, detail::new_node< string_node >);
-    try {
-        leaf_node& child = dynamic_cast< leaf_node& >(*raw_node);
-        child.set_string(raw_value);
-    } catch (const std::bad_cast& unused_error) {
+    leaf_node* child = dynamic_cast< leaf_node* >(raw_node);
+    if (child != NULL) {
+        child->set_string(raw_value);
+    } else {
         throw value_error(F("Invalid value for key '%s'") %
                           detail::flatten_key(key));
     }
@@ -247,11 +246,11 @@ config::tree::all_properties(const std::string& dotted_key,
         key = detail::parse_key(dotted_key);
         raw_node = _root->lookup_ro(key, 0);
     }
-    try {
-        const detail::inner_node& child =
-            dynamic_cast< const detail::inner_node& >(*raw_node);
-        child.all_properties(properties, key);
-    } catch (const std::bad_cast& unused_error) {
+    const detail::inner_node* child =
+        dynamic_cast< const detail::inner_node* >(raw_node);
+    if (child != NULL) {
+        child->all_properties(properties, key);
+    } else {
         INV(!dotted_key.empty());
         throw value_error(F("Cannot export properties from a leaf node; "
                             "'%s' given") % dotted_key);
