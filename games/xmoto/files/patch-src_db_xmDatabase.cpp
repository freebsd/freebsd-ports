--- src/db/xmDatabase.cpp.orig	2024-04-30 19:43:06 UTC
+++ src/db/xmDatabase.cpp
@@ -58,6 +58,10 @@ void xmDatabase::openIfNot(const std::string &i_dbFile
                     ") : " + sqlite3_errmsg(m_db));
   }
 
+#ifdef SQLITE_DBCONFIG_DQS_DML
+  sqlite3_db_config(m_db, SQLITE_DBCONFIG_DQS_DML, 1, NULL);
+#endif
+
   sqlite3_busy_timeout(m_db, DB_BUSY_TIMEOUT);
   sqlite3_trace(m_db, sqlTrace, NULL);
   createUserFunctions();
