--- client.cpp.orig	2011-11-07 18:39:52.000000000 +0100
+++ client.cpp	2011-11-07 18:55:26.000000000 +0100
@@ -63,12 +63,18 @@
         conoutf("could not resolve server %s", servername);
         return;
     };
-
+#if ENET_VERSION > 130
+    clienthost = enet_host_create(NULL, 1, 0, rate, rate);
+#else
     clienthost = enet_host_create(NULL, 1, rate, rate);
-
+#endif
     if(clienthost)
     {
+#if ENET_VERSION > 130
+        enet_host_connect(clienthost, &address, 1, 0); 
+#else
         enet_host_connect(clienthost, &address, 1); 
+#endif
         enet_host_flush(clienthost);
         connecting = lastmillis;
         connattempts = 0;
@@ -86,7 +92,7 @@
     {
         if(!connecting && !disconnecting) 
         {
-            enet_peer_disconnect(clienthost->peers);
+            enet_peer_disconnect(clienthost->peers, 0);
             enet_host_flush(clienthost);
             disconnecting = lastmillis;
         };
@@ -304,6 +310,9 @@
             if(disconnecting) disconnect();
             else server_err();
             return;
+
+	default:
+	    return;
     }
 };
 
