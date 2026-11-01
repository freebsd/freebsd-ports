DQS is disabled for databases/sqlite3 since 3.45.1
DQS_DML: enables double-quoted string literals in
         INSERT, SELECT, UPDATE, and DELETE.

--- tests/test_plugins.py.orig	2026-10-19 03:55:36 UTC
+++ tests/test_plugins.py
@@ -118,6 +118,7 @@ def test_prepare_connection():
         ]
 
         db = Database(memory=True)
+        db.conn.setconfig(sqlite3.SQLITE_DBCONFIG_DQS_DML, True)
         assert "hello" in _functions(db)
         result = db.execute('select hello("world")').fetchone()[0]
         assert result == "Hello, world!"
