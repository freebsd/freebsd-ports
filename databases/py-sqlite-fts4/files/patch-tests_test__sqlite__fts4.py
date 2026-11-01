DQS is disabled for databases/sqlite3 since 3.45.1
DQS_DML: enables double-quoted string literals in
         INSERT, SELECT, UPDATE, and DELETE.

--- tests/test_sqlite_fts4.py.orig	2026-10-18 14:49:03 UTC
+++ tests/test_sqlite_fts4.py
@@ -20,6 +20,7 @@ def conn():
 def conn():
     conn = sqlite3.connect(":memory:")
     register_functions(conn)
+    conn.setconfig(sqlite3.SQLITE_DBCONFIG_DQS_DML, True)
     conn.executescript(
         """
 CREATE VIRTUAL TABLE search USING fts4(c0, c1);
