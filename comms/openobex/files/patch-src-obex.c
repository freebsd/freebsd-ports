--- src/obex.c.orig	Mon Mar 22 18:16:53 2004
+++ src/obex.c	Mon Mar 22 18:21:35 2004
@@ -990,7 +990,11 @@
 
 #ifdef HAVE_BLUETOOTH
 	if(src == NULL)
+#ifdef HAVE_BLUETOOTH_NETGRAPH
+		src = NG_HCI_BDADDR_ANY;
+#else /*HAVE_BLUETOOTH_NETGRAPH*/
 		src = BDADDR_ANY;
+#endif /*HAVE_BLUETOOTH_NETGRAPH*/
 	btobex_prepare_listen(self, src, channel);
 	return obex_transport_listen(self);
 #else
@@ -1019,7 +1023,11 @@
 
 #ifdef HAVE_BLUETOOTH
 	if(src == NULL)
+#ifdef HAVE_BLUETOOTH_NETGRAPH
+		src = NG_HCI_BDADDR_ANY;
+#else /*HAVE_BLUETOOTH_NETGRAPH*/
 		src = BDADDR_ANY;
+#endif /*HAVE_BLUETOOTH_NETGRAPH*/
 	btobex_prepare_connect(self, src, dst, channel);
 	return obex_transport_connect_request(self);
 #else
