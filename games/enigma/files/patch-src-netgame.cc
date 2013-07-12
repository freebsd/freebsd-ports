--- src/netgame.cc.orig	2011-11-07 19:55:38.000000000 +0100
+++ src/netgame.cc	2011-11-07 19:59:07.000000000 +0100
@@ -154,8 +154,11 @@
 
     network_address.host = ENET_HOST_ANY;
     network_address.port = 12345;
-
+#if ENET_VERSION > 130
+    network_host = enet_host_create (&network_address, 1, 0, 0, 0);
+#else
     network_host = enet_host_create (&network_address, 1, 0, 0);
+#endif
     if (network_host == NULL) {
         fprintf (stderr, 
                  "SV: An error occurred while trying to create an ENet server host.\n");
@@ -240,6 +243,9 @@
     ENetHost *m_network_host;
     m_network_host = enet_host_create (NULL,
                                        1 /* only allow 1 outgoing connection */,
+#if ENET_VERSION > 130
+                                       0,
+#endif
                                        57600 / 8 /* 56K modem with 56 Kbps downstream bandwidth */,
                                        14400 / 8 /* 56K modem with 14 Kbps upstream bandwidth */);
 
@@ -260,8 +266,11 @@
 
     /* Initiate the connection, allocating the two channels 0 and 1. */
     int numchannels = 2;
+#if ENET_VERSION > 130
+    m_server = enet_host_connect (m_network_host, &sv_address, numchannels, 0);
+#else
     m_server = enet_host_connect (m_network_host, &sv_address, numchannels);
-    
+#endif
     if (m_server == NULL) {
         fprintf (stderr, 
                  "CL: No available peers for initiating an ENet connection.\n");
