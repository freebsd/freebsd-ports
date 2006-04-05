--- src/xmms/ipc.c.orig	Sat Apr  1 23:59:54 2006
+++ src/xmms/ipc.c	Sun Apr  2 00:00:09 2006
@@ -795,8 +795,8 @@
 xmms_ipc_shutdown_server(xmms_ipc_t *ipc) 
 {
 	GList *c;
-	if(!ipc) return;
 	xmms_ipc_client_t *co;
+	if(!ipc) return;
 	
 	g_mutex_lock (ipc->mutex_lock);
 	g_source_remove_poll (ipc->source, ipc->pollfd);
