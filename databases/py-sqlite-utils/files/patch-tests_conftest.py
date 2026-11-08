DQS is disabled for databases/sqlite3 since 3.45.1
DQS_DML: enables double-quoted string literals in
         INSERT, SELECT, UPDATE, and DELETE.

--- tests/conftest.py.orig	2026-10-19 03:54:19 UTC
+++ tests/conftest.py
@@ -68,6 +68,7 @@ def existing_db():
 @pytest.fixture
 def existing_db():
     database = Database(memory=True)
+    database.conn.setconfig(sqlite3.SQLITE_DBCONFIG_DQS_DML, True)
     database.executescript("""
         CREATE TABLE foo (text TEXT);
         INSERT INTO foo (text) values ("one");
