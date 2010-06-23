--- src/engine/server/es_server.c.orig	2010-06-23 09:41:50.000000000 +0200
+++ src/engine/server/es_server.c	2010-06-23 09:42:21.000000000 +0200
@@ -303,7 +303,7 @@
 
 void server_kick(int client_id, const char *reason)
 {
-	if(client_id < 0 || client_id > MAX_CLIENTS)
+	if(client_id < 0 || client_id >= MAX_CLIENTS)
 		return;
 		
 	if(clients[client_id].state != SRVCLIENT_STATE_EMPTY)
@@ -1244,7 +1244,7 @@
 		NETADDR addr;
 		int cid = atoi(str);
 
-		if(cid < 0 || cid > MAX_CLIENTS || clients[cid].state == SRVCLIENT_STATE_EMPTY)
+		if(cid < 0 || cid >= MAX_CLIENTS || clients[cid].state == SRVCLIENT_STATE_EMPTY)
 		{
 			dbg_msg("server", "invalid client id");
 			return;
