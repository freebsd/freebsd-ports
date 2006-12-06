--- lib/obex.c.orig	Thu May 25 20:09:41 2006
+++ lib/obex.c	Sat Nov 25 22:04:07 2006
@@ -1031,7 +1031,11 @@
 
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
@@ -1061,7 +1065,11 @@
 
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
