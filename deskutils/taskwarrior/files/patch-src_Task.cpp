--- src/Task.cpp.orig	2025-08-16 19:02:31 UTC
+++ src/Task.cpp
@@ -660,10 +660,19 @@
 
         auto atts = (json::array*)i.second;
         for (auto& annotations : atts->_data) {
+          // Fail if the annotation is not an object.
+          if (annotations->type() != json::j_object) {
+            throw format("Annotation is malformed: {1}", annotations->dump());
+          }
+
           auto annotation = (json::object*)annotations;
 
-          // Extract description. Fail if not present.
-          auto what = (json::string*)annotation->_data["description"];
+          // Extract description. Fail if not present or not a string.
+          auto description_node = annotation->_data["description"];
+          if (description_node && description_node->type() != json::j_string) {
+            throw format("Annotation description is not a string: {1}", description_node->dump());
+          }
+          auto what = (json::string*)description_node;
           if (!what) {
             annotation->_data.erase(
                 "description");  // Erase NULL description inserted by failed lookup above
@@ -675,7 +684,11 @@
           long long ann_timestamp;
 
           // Extract entry. Use current time if not present.
-          auto when = (json::string*)annotation->_data["entry"];
+          auto entry_node = annotation->_data["entry"];
+          if (entry_node && entry_node->type() != json::j_string) {
+            throw format("Annotation entry is not a string: {1}", entry_node->dump());
+          }
+          auto when = (json::string*)entry_node;
           if (when)
             ann_timestamp = (long long)(Datetime(when->_data).toEpoch());
           else {
