--- utils/config/nodes.cpp.old
+++ utils/config/nodes.cpp
@@ -112,11 +112,11 @@ config::detail::inner_node::lookup_ro(const tree_key& key,
         return (*child_iter).second;
     } else {
         PRE(key_pos < key.size() - 1);
-        try {
-            const inner_node& child = dynamic_cast< const inner_node& >(
-                *(*child_iter).second);
-            return child.lookup_ro(key, key_pos + 1);
-        } catch (const std::bad_cast& e) {
+        const inner_node* child = dynamic_cast< const inner_node* >(
+                (*child_iter).second);
+        if (child != NULL) {
+            return child->lookup_ro(key, key_pos + 1);
+        } else {
             throw unknown_key_error(
                 key, "Cannot address incomplete configuration property '%s'");
         }
@@ -163,21 +163,19 @@ config::detail::inner_node::lookup_rw(const tree_key& key,
     }
 
     if (key_pos == key.size() - 1) {
-        try {
-            leaf_node& child = dynamic_cast< leaf_node& >(
-                *(*child_iter).second);
-            return &child;
-        } catch (const std::bad_cast& unused_error) {
+        leaf_node* child = dynamic_cast< leaf_node* >((*child_iter).second);
+        if (child != NULL) {
+            return child;
+        } else {
             throw value_error(F("Invalid value for key '%s'") %
                               flatten_key(key));
         }
     } else {
         PRE(key_pos < key.size() - 1);
-        try {
-            inner_node& child = dynamic_cast< inner_node& >(
-                *(*child_iter).second);
-            return child.lookup_rw(key, key_pos + 1, new_node);
-        } catch (const std::bad_cast& e) {
+        inner_node* child = dynamic_cast< inner_node* >((*child_iter).second);
+        if (child != NULL) {
+            return child->lookup_rw(key, key_pos + 1, new_node);
+        } else {
             throw unknown_key_error(
                 key, "Cannot address incomplete configuration property '%s'");
         }
@@ -198,13 +196,14 @@ config::detail::inner_node::all_properties(properties_map& properties,
          iter != _children.end(); ++iter) {
         tree_key child_key = key;
         child_key.push_back((*iter).first);
-        try {
-            leaf_node& child = dynamic_cast< leaf_node& >(*(*iter).second);
-            if (child.is_set())
-                properties[flatten_key(child_key)] = child.to_string();
-        } catch (const std::bad_cast& unused_error) {
-            inner_node& child = dynamic_cast< inner_node& >(*(*iter).second);
-            child.all_properties(properties, child_key);
+        leaf_node* child = dynamic_cast< leaf_node* >((*iter).second);
+        if (child != NULL) {
+            if (child->is_set())
+                properties[flatten_key(child_key)] = child->to_string();
+        } else {
+            inner_node* child2 = dynamic_cast< inner_node* >((*iter).second);
+            INV(child2 != NULL);
+            child2->all_properties(properties, child_key);
         }
     }
 }
@@ -261,11 +260,11 @@ config::detail::static_inner_node::define(const tree_key& key,
             _children.insert(children_map::value_type(key[key_pos], child_ptr));
             child_ptr->define(key, key_pos + 1, new_node);
         } else {
-            try {
-                static_inner_node& child = dynamic_cast< static_inner_node& >(
-                    *(*child_iter).second);
-                child.define(key, key_pos + 1, new_node);
-            } catch (const std::bad_cast& e) {
+            static_inner_node* child = dynamic_cast< static_inner_node* >(
+                (*child_iter).second);
+            if (child != NULL) {
+                child->define(key, key_pos + 1, new_node);
+            } else {
                 UNREACHABLE;
             }
         }
