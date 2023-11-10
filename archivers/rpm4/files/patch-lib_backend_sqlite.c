--- lib/backend/sqlite.c.orig	2023-09-06 20:53:16 UTC
+++ lib/backend/sqlite.c
@@ -44,13 +44,6 @@ static void rpm_match3(sqlite3_context *sctx, int argc
     sqlite3_result_int(sctx, match);
 }
 
-static void errCb(void *data, int err, const char *msg)
-{
-    rpmdb rdb = data;
-    rpmlog(RPMLOG_WARNING, "%s: %s: %s\n",
-		rdb->db_descr, sqlite3_errstr(err), msg);
-}
-
 static int dbiCursorReset(dbiCursor dbc)
 {
     if (dbc->stmt) {
@@ -170,7 +163,6 @@ static int sqlite_init(rpmdb rdb, const char * dbhome)
 	 * the "database is locked" errors at every cost
 	 */
 	sqlite3_busy_timeout(sdb, 10000);
-	sqlite3_config(SQLITE_CONFIG_LOG, errCb, rdb);
 
 	sqlexec(sdb, "PRAGMA secure_delete = OFF");
 	sqlexec(sdb, "PRAGMA case_sensitive_like = ON");
