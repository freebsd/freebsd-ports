--- recovery.c.orig	2009-08-14 15:15:08.000000000 +0900
+++ recovery.c	2009-08-14 18:00:38.000000000 +0900
@@ -91,7 +91,7 @@
 
 	pool_log("1st stage is done");
 
-	pool_log("starting 2nd stage");
+	pool_log("starting 2nd stage.  waiting connections from clients to be closed");
 
 	/* 2nd stage */
 	*InRecovery = 1;
@@ -332,6 +332,6 @@
 			sleep(3);
 	} while (i++ < WAIT_RETRY_COUNT);
 
-	pool_error("wait_connection_closed: existing connections did not close in %d sec.", pool_config->recovery_timeout);
+	pool_error("wait_connection_closed: existing connections (%d) did not close in %d sec.", Req_info->conn_counter, pool_config->recovery_timeout);
 	return 1;
 }
