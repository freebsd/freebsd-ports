--- ./recovery.c.orig	2014-03-24 14:30:01.000000000 +0000
+++ ./recovery.c	2014-06-29 14:55:21.756363519 +0100
@@ -117,7 +117,7 @@
 
 	if (REPLICATION)
 	{
-		pool_log("starting 2nd stage");
+		pool_log("starting 2nd stage.  waiting connections from clients to be closed");
 
 		/* 2nd stage */
 		*InRecovery = RECOVERY_ONLINE;
@@ -430,6 +430,6 @@
 			sleep(3);
 	} while (i++ < WAIT_RETRY_COUNT);
 
-	pool_error("wait_connection_closed: existing connections did not close in %d sec.", pool_config->recovery_timeout);
+	pool_error("wait_connection_closed: existing connections (%d) did not close in %d sec.", Req_info->conn_counter, pool_config->recovery_timeout);
 	return 1;
 }
