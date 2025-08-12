--- urbackupserver/server_cleanup.cpp.orig	2025-08-11 16:00:31 UTC
+++ urbackupserver/server_cleanup.cpp
@@ -78,7 +78,7 @@ ServerCleanupThread::ServerCleanupThread(CleanupAction
 }
 
 ServerCleanupThread::ServerCleanupThread(CleanupAction cleanup_action)
-	: cleanup_action(cleanup_action), cleanupdao(NULL), backupdao(NULL)
+	: cleanup_action(cleanup_action), cleanupdao(), backupdao()
 {
 	logid = ServerLogger::getLogId(LOG_CATEGORY_CLEANUP);
 }
