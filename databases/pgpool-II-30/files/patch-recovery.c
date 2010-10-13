--- recovery.c.orig	2010-10-12 08:12:18.155163331 +0900
+++ recovery.c	2010-10-12 08:13:21.347257609 +0900
@@ -96,7 +96,7 @@
 
 	if (REPLICATION)
 	{
-		pool_log("starting 2nd stage");
+		pool_log("starting 2nd stage.  waiting connections from clients to be closed");
 
 		/* 2nd stage */
 		*InRecovery = 1;
@@ -384,6 +384,6 @@
 			sleep(3);
 	} while (i++ < WAIT_RETRY_COUNT);
 
-	pool_error("wait_connection_closed: existing connections did not close in %d sec.", pool_config->recovery_timeout);
+	pool_error("wait_connection_closed: existing connections (%d) did not close in %d sec.", Req_info->conn_counter, pool_config->recovery_timeout);
 	return 1;
 }
