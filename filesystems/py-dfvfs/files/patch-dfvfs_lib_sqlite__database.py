--- dfvfs/lib/sqlite_database.py.orig	2023-12-03 10:56:43 UTC
+++ dfvfs/lib/sqlite_database.py
@@ -14,7 +14,7 @@ class SQLiteDatabaseFile(object):
   _HAS_COLUMN_QUERY = 'PRAGMA table_info("{0:s}")'
 
   _HAS_TABLE_QUERY = (
-      'SELECT name FROM sqlite_master WHERE type = "table"')
+      'SELECT name FROM sqlite_master WHERE type = \'table\'')
 
   _HEADER_SIGNATURE = b'SQLite format 3'
 
