--- mongomock/collection.py.orig	2026-11-10 02:57:44 UTC
+++ mongomock/collection.py
@@ -189,14 +189,14 @@ class BulkWriteOperation:
             return ret_val
         self.builder.executors.append(exec_update)
 
-    def update(self, document, hint=None):
-        self.register_update_op(document, multi=True, hint=hint)
+    def update(self, document, hint=None, sort=None):
+        self.register_update_op(document, multi=True, hint=hint, sort=sort)
 
-    def update_one(self, document, hint=None):
-        self.register_update_op(document, multi=False, hint=hint)
+    def update_one(self, document, hint=None, sort=None):
+        self.register_update_op(document, multi=False, hint=hint, sort=sort)
 
-    def replace_one(self, document, hint=None):
-        self.register_update_op(document, multi=False, remove=True, hint=hint)
+    def replace_one(self, document, hint=None, sort=None):
+        self.register_update_op(document, multi=False, remove=True, hint=hint, sort=sort)
 
 
 def _combine_projection_spec(projection_fields_spec):
@@ -392,16 +392,16 @@ class BulkOperationBuilder:
         self.insert(doc)
 
     def add_update(self, selector, doc, multi=False, upsert=False, collation=None,
-                   array_filters=None, hint=None):
+                   array_filters=None, hint=None, sort=None):
         if array_filters:
             raise_not_implemented(
                 'array_filters', 'Array filters are not implemented in mongomock yet.')
         write_operation = BulkWriteOperation(self, selector, is_upsert=upsert)
-        write_operation.register_update_op(doc, multi, hint=hint)
+        write_operation.register_update_op(doc, multi, hint=hint, sort=sort)
 
-    def add_replace(self, selector, doc, upsert, collation=None, hint=None):
+    def add_replace(self, selector, doc, upsert, collation=None, hint=None, sort=None):
         write_operation = BulkWriteOperation(self, selector, is_upsert=upsert)
-        write_operation.replace_one(doc, hint=hint)
+        write_operation.replace_one(doc, hint=hint, sort=sort)
 
     def add_delete(self, selector, just_one, collation=None, hint=None):
         write_operation = BulkWriteOperation(self, selector, is_upsert=False)
