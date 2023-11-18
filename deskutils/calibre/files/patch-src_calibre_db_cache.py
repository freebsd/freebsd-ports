--- src/calibre/db/cache.py.orig	2023-11-17 06:02:05 UTC
+++ src/calibre/db/cache.py
@@ -687,7 +687,7 @@ class Cache:
         return self.backend.notes_data_for(field, item_id)
 
     @read_api
-    def get_all_items_that_have_notes(self, field_name=None) -> set[int] | dict[str, set[int]]:
+    def get_all_items_that_have_notes(self, field_name=None) -> "set[int] | dict[str, set[int]]":
         ' Return all item_ids for items that have notes in the specified field or all fields if field_name is None '
         return self.backend.get_all_items_that_have_notes(field_name)
 
