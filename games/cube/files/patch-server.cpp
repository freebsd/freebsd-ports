--- server.cpp.orig	2011-11-07 18:57:19.000000000 +0100
+++ server.cpp	2011-11-07 19:01:52.000000000 +0100
@@ -104,7 +104,7 @@
 void disconnect_client(int n, char *reason)
 {
     printf("disconnecting client (%s) [%s]\n", clients[n].hostname, reason);
-    enet_peer_disconnect(clients[n].peer);
+    enet_peer_disconnect(clients[n].peer, 0);
     clients[n].type = ST_EMPTY;
     send2(true, -1, SV_CDIS, n);
 };
@@ -397,17 +397,20 @@
             }
             case ENET_EVENT_TYPE_RECEIVE:
                 brec += event.packet->dataLength;
-                process(event.packet, (int)event.peer->data); 
+                process(event.packet, (intptr_t)event.peer->data); 
                 if(event.packet->referenceCount==0) enet_packet_destroy(event.packet);
                 break;
 
             case ENET_EVENT_TYPE_DISCONNECT: 
-                if((int)event.peer->data<0) break;
-                printf("disconnected client (%s)\n", clients[(int)event.peer->data].hostname);
-                clients[(int)event.peer->data].type = ST_EMPTY;
-                send2(true, -1, SV_CDIS, (int)event.peer->data);
+                if((intptr_t)event.peer->data<0) break;
+                printf("disconnected client (%s)\n", clients[(intptr_t)event.peer->data].hostname);
+                clients[(intptr_t)event.peer->data].type = ST_EMPTY;
+                send2(true, -1, SV_CDIS, (intptr_t)event.peer->data);
                 event.peer->data = (void *)-1;
                 break;
+
+	     default:
+		break;
         };
         
         if(numplayers>maxclients)   
@@ -448,7 +451,11 @@
     {
         ENetAddress address = { ENET_HOST_ANY, CUBE_SERVER_PORT };
         if(*ip && enet_address_set_host(&address, ip)<0) printf("WARNING: server ip not resolved");
+#if ENET_VERSION > 130
+        serverhost = enet_host_create(&address, MAXCLIENTS, 0, 0, uprate);
+#else
         serverhost = enet_host_create(&address, MAXCLIENTS, 0, uprate);
+#endif
         if(!serverhost) fatal("could not create server host\n");
         loopi(MAXCLIENTS) serverhost->peers[i].data = (void *)-1;
     };
