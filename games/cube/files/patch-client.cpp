--- client.cpp.orig	Tue Feb  6 01:24:56 2007
+++ client.cpp	Tue Feb  6 01:26:30 2007
@@ -86,7 +86,7 @@
     {
         if(!connecting && !disconnecting) 
         {
-            enet_peer_disconnect(clienthost->peers);
+            enet_peer_disconnect(clienthost->peers, 0);
             enet_host_flush(clienthost);
             disconnecting = lastmillis;
         };
@@ -304,6 +304,9 @@
             if(disconnecting) disconnect();
             else server_err();
             return;
+
+	default:
+	    return;
     }
 };
 
