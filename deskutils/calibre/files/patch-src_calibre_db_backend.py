--- src/calibre/db/backend.py.orig	2023-02-17 02:32:09 UTC
+++ src/calibre/db/backend.py
@@ -1385,8 +1385,8 @@ class DB:
     @property
     def custom_tables(self):
         return {x[0] for x in self.conn.get(
-            'SELECT name FROM sqlite_master WHERE type="table" AND '
-            '(name GLOB "custom_column_*" OR name GLOB "books_custom_column_*")')}
+            'SELECT name FROM sqlite_master WHERE type=\'table\' AND '
+            '(name GLOB \'custom_column_*\' OR name GLOB \'books_custom_column_*\')')}
 
     @classmethod
     def exists_at(cls, path):
