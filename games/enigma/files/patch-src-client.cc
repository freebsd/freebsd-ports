--- src/client.cc.orig	2011-11-07 19:49:08.000000000 +0100
+++ src/client.cc	2011-11-07 19:53:20.000000000 +0100
@@ -128,6 +128,9 @@
 
     m_network_host = enet_host_create (NULL,
                                        1 /* only allow 1 outgoing connection */,
+#if ENET_VERSION > 130
+                                       0,
+#endif
                                        57600 / 8 /* 56K modem with 56 Kbps downstream bandwidth */,
                                        14400 / 8 /* 56K modem with 14 Kbps upstream bandwidth */);
 
@@ -148,8 +151,11 @@
     sv_address.port = 12345;
 
     /* Initiate the connection, allocating the two channels 0 and 1. */
+#if ENET_VERSION > 130
+    m_server = enet_host_connect (m_network_host, &sv_address, 2, 0);
+#else
     m_server = enet_host_connect (m_network_host, &sv_address, 2);    
-    
+#endif    
     if (m_server == NULL) {
        fprintf (stderr, 
                 "No available peers for initiating an ENet connection.\n");
