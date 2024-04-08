Allow evolution to be used when databases/sqlite3 has been compiled
with option DQS disabled.

--- src/camel/camel-db.c.orig	2024-04-08 09:37:09 UTC
+++ src/camel/camel-db.c
@@ -1823,8 +1823,8 @@ camel_db_migrate_folder_prepare (CamelDB *cdb,
 			"mail_to , mail_cc , mlist , followup_flag , "
 			"followup_completed_on , followup_due_by , "
 			"part , labels , usertags , cinfo , bdata , '', '', "
-			"strftime(\"%%s\", 'now'), "
-			"strftime(\"%%s\", 'now') FROM %Q",
+			"strftime('%%s', 'now'), "
+			"strftime('%%s', 'now') FROM %Q",
 			folder_name, folder_name);
 		ret = camel_db_add_to_transaction (cdb, table_creation_query, error);
 		sqlite3_free (table_creation_query);
@@ -2093,8 +2093,8 @@ camel_db_write_message_info_record (CamelDB *cdb,
 		"%Q, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, "
 		"%lld, %lld, %Q, %Q, %Q, %Q, %Q, %Q, %Q, %Q, "
 		"%Q, %Q, %Q, %Q, %Q, %Q, %Q, "
-		"strftime(\"%%s\", 'now'), "
-		"strftime(\"%%s\", 'now') )",
+		"strftime('%%s', 'now'), "
+		"strftime('%%s', 'now') )",
 		folder_name,
 		record->uid,
 		record->flags,
@@ -2578,7 +2578,7 @@ camel_db_rename_folder (CamelDB *cdb,
 	ret = camel_db_add_to_transaction (cdb, cmd, error);
 	sqlite3_free (cmd);
 
-	cmd = sqlite3_mprintf ("UPDATE %Q SET modified=strftime(\"%%s\", 'now'), created=strftime(\"%%s\", 'now')", new_folder_name);
+	cmd = sqlite3_mprintf ("UPDATE %Q SET modified=strftime('%%s', 'now'), created=strftime('%%s', 'now')", new_folder_name);
 	ret = camel_db_add_to_transaction (cdb, cmd, error);
 	sqlite3_free (cmd);
 
