--- src/libebackend/e-cache.c.orig	2024-06-28 10:29:41.000000000 +0300
+++ src/libebackend/e-cache.c	2025-02-17 23:37:07.031025000 +0300
@@ -761,6 +761,10 @@
 		return FALSE;
 	}
 
+	/*Enable Double-Quoted*/
+	sqlite3_db_config(cache->priv->db, SQLITE_DBCONFIG_DQS_DDL, 1, (void*)0);
+	sqlite3_db_config(cache->priv->db, SQLITE_DBCONFIG_DQS_DML, 1, (void*)0);
+
 	/* Handle GCancellable */
 	sqlite3_progress_handler (
 		cache->priv->db,
