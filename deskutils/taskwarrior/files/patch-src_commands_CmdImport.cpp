--- src/commands/CmdImport.cpp.orig	2025-08-16 19:02:31 UTC
+++ src/commands/CmdImport.cpp
@@ -123,6 +123,11 @@
 
         // For each object element...
         for (auto& element : root_arr->_data) {
+          // Fail if the element is not an object.
+          if (element->type() != json::j_object) {
+            throw format("Invalid JSON: array element is not an object: {1}", element->dump());
+          }
+
           // For each object element...
           auto root_obj = (json::object*)element;
           importSingleTask(root_obj);
