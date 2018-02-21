--- recovery.c.orig	2018-02-13 05:20:52 UTC
+++ recovery.c
@@ -115,7 +115,7 @@ int start_recovery(int recovery_node)
 
 	if (REPLICATION)
 	{
-		pool_log("starting 2nd stage");
+		pool_log("starting 2nd stage.  waiting connections from clients to be closed");
 
 		/* 2nd stage */
 		*InRecovery = RECOVERY_ONLINE;
@@ -437,6 +437,6 @@ int wait_connection_closed(void)
 			sleep(3);
 	} while (i++ < WAIT_RETRY_COUNT);
 
-	pool_error("wait_connection_closed: existing connections did not close in %d sec.", pool_config->recovery_timeout);
+	pool_error("wait_connection_closed: existing connections (%d) did not close in %d sec.", Req_info->conn_counter, pool_config->recovery_timeout);
 	return 1;
 }
