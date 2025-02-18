--- src/addressbook/libedata-book/e-book-sqlite.c.org	2024-06-28 10:29:41.000000000 +0300
+++ src/addressbook/libedata-book/e-book-sqlite.c	2025-02-17 23:44:47.262878000 +0300
@@ -1888,6 +1888,10 @@
 		ebsql_check_cancel,
 		ebsql);
 
+	/*Enable Double-Quoted*/
+	sqlite3_db_config(ebsql->priv->db, SQLITE_DBCONFIG_DQS_DDL, 1, (void*)0);
+	sqlite3_db_config(ebsql->priv->db, SQLITE_DBCONFIG_DQS_DML, 1, (void*)0);
+
 	/* Install our custom functions */
 	for (i = 0; ret == SQLITE_OK && i < G_N_ELEMENTS (ebsql_custom_functions); i++)
 		ret = sqlite3_create_function (
