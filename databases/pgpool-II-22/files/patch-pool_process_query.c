--- pool_process_query.c.orig	Mon Apr 16 12:08:40 2007
+++ pool_process_query.c	Mon Apr 16 12:09:54 2007
@@ -3906,10 +3906,13 @@
 							   i, k, *kind);
 					pool_send_error_message(frontend, MAJOR(backend), "XX000", 
 											"kind mismatch between backends", "",
-											"check data consistency between master and secondary", __FILE__, __LINE__);
+											"check data consistency between master and other db node", __FILE__, __LINE__);
 
 					if (pool_config->replication_stop_on_mismatch)
-						return POOL_FATAL;
+					{
+						notice_backend_error(i);
+						child_exit(1);
+					}
 					else
 						return POOL_ERROR;
 				}
