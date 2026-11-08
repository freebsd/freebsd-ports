DQS is disabled for databases/sqlite3 since 3.45.1
DQS_DML: enables double-quoted string literals in
         INSERT, SELECT, UPDATE, and DELETE.

--- tests/test_register_function.py.orig	2026-10-19 03:51:50 UTC
+++ tests/test_register_function.py
@@ -10,6 +10,7 @@ def test_register_function(fresh_db):
     def reverse_string(s):
         return "".join(reversed(list(s)))
 
+    fresh_db.conn.setconfig(sqlite3.SQLITE_DBCONFIG_DQS_DML, True)
     result = fresh_db.execute('select reverse_string("hello")').fetchone()[0]
     assert result == "olleh"
 
@@ -19,6 +20,7 @@ def test_register_function_custom_name(fresh_db):
     def reverse_string(s):
         return "".join(reversed(list(s)))
 
+    fresh_db.conn.setconfig(sqlite3.SQLITE_DBCONFIG_DQS_DML, True)
     result = fresh_db.execute('select revstr("hello")').fetchone()[0]
     assert result == "olleh"
 
