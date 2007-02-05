--- server.cpp.orig	Tue Feb  6 01:26:35 2007
+++ server.cpp	Tue Feb  6 01:27:06 2007
@@ -104,7 +104,7 @@
 void disconnect_client(int n, char *reason)
 {
     printf("disconnecting client (%s) [%s]\n", clients[n].hostname, reason);
-    enet_peer_disconnect(clients[n].peer);
+    enet_peer_disconnect(clients[n].peer, 0);
     clients[n].type = ST_EMPTY;
     send2(true, -1, SV_CDIS, n);
 };
@@ -408,6 +408,9 @@
                 send2(true, -1, SV_CDIS, (int)event.peer->data);
                 event.peer->data = (void *)-1;
                 break;
+
+	     default:
+		break;
         };
         
         if(numplayers>maxclients)   
