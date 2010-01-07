--- ./src/ha_pinba.cc.orig	2009-12-23 23:55:04.000000000 -0500
+++ ./src/ha_pinba.cc	2010-01-07 16:22:50.000000000 -0500
@@ -283,6 +283,7 @@
 	int error = 0;
 	DBUG_ENTER("pinba_engine_shutdown");
 
+	pthread_detach(collector_thread);
 	pthread_cancel(collector_thread);
 	pthread_join(collector_thread, NULL);
 
