--- src/camel/camel-db.c.orig	2024-06-28 10:29:41.000000000 +0300
+++ src/camel/camel-db.c	2025-02-17 23:40:46.536455000 +0300
@@ -842,6 +842,10 @@
 	cdb->priv->filename = g_strdup (filename);
 	d (g_print ("\nDatabase successfully opened  \n"));
 
+	/*Enable Double-Quoted*/
+	sqlite3_db_config(db, SQLITE_DBCONFIG_DQS_DDL, 1, (void*)0);
+	sqlite3_db_config(db, SQLITE_DBCONFIG_DQS_DML, 1, (void*)0);
+
 	sqlite3_create_function (db, "MATCH", 2, SQLITE_UTF8, NULL, cdb_match_func, NULL, NULL);
 	sqlite3_create_function (db, "CAMELCOMPAREDATE", 2, SQLITE_UTF8, NULL, cdb_camel_compare_date_func, NULL, NULL);
 
