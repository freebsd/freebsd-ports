DQS is disabled for databases/sqlite3 since 3.45.1

--- sqlite_utils/db.py.orig	2026-10-19 03:45:14 UTC
+++ sqlite_utils/db.py
@@ -3932,7 +3932,7 @@ class Table(Queryable):
         if fts_table is not None:
             with self.db.atomic():
                 self.db.execute("""
-                    INSERT INTO {table} ({table}) VALUES ("optimize");
+                    INSERT INTO {table} ({table}) VALUES ('optimize');
                 """.strip().format(table=quote_identifier(fts_table)))
         return self
 
