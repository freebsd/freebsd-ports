--- blueprintcompiler/gir.py.orig	2023-09-26 21:07:04 UTC
+++ blueprintcompiler/gir.py
@@ -888,8 +888,8 @@ class Repository(GirNode):
             return self.lookup_namespace(ns).get_type(dir_entry.DIR_ENTRY_NAME)
 
     def _resolve_type_id(self, type_id: int) -> GirType:
-        if type_id & 0xFFFFFF == 0:
-            type_id = (type_id >> 27) & 0x1F
+        if type_id & (0xFFFFFF if sys.byteorder == "little" else 0xFFFFFF00) == 0:
+            type_id = ((type_id >> 27) if sys.byteorder == "little" else type_id) & 0x1F
             # simple type
             if type_id == typelib.TYPE_BOOLEAN:
                 return BoolType()
