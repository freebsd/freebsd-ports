--- src/btobex.c.orig	Mon Mar 22 18:31:43 2004
+++ src/btobex.c	Mon Mar 22 18:44:46 2004
@@ -46,8 +46,12 @@
 #include <netinet/in.h>
 #include <sys/socket.h>
 
+#ifdef HAVE_BLUETOOTH_NETGRAPH
+#include <bluetooth.h>
+#else /*HAVE_BLUETOOTH_NETGRAPH*/
 #include <bluetooth/bluetooth.h>
 #include <bluetooth/rfcomm.h>
+#endif /*HAVE_BLUETOOTH_NETGRAPH*/
 
 #endif /* _WIN32 */
 
@@ -65,6 +69,15 @@
 void btobex_prepare_connect(obex_t *self, bdaddr_t *src, bdaddr_t *dst, uint8_t channel)
 {
 #ifndef _WIN32
+#ifdef HAVE_BLUETOOTH_NETGRAPH
+	self->trans.self.rfcomm.rfcomm_family = AF_BLUETOOTH;
+	bacpy(&self->trans.self.rfcomm.rfcomm_bdaddr, src);
+	self->trans.self.rfcomm.rfcomm_channel = 0;
+
+	self->trans.peer.rfcomm.rfcomm_family = AF_BLUETOOTH;
+	bacpy(&self->trans.peer.rfcomm.rfcomm_bdaddr, dst);
+	self->trans.peer.rfcomm.rfcomm_channel = channel;
+#else /*HAVE_BLUETOOTH_NETGRAPH*/
 	self->trans.self.rfcomm.rc_family = AF_BLUETOOTH;
 	bacpy(&self->trans.self.rfcomm.rc_bdaddr, src);
 	self->trans.self.rfcomm.rc_channel = 0;
@@ -72,6 +85,7 @@
 	self->trans.peer.rfcomm.rc_family = AF_BLUETOOTH;
 	bacpy(&self->trans.peer.rfcomm.rc_bdaddr, dst);
 	self->trans.peer.rfcomm.rc_channel = channel;
+#endif /*HAVE_BLUETOOTH_NETGRAPH*/
 #endif /* _WIN32 */
 }
 
@@ -85,9 +99,15 @@
 {
 #ifndef _WIN32
 	/* Bind local service */
+#ifdef HAVE_BLUETOOTH_NETGRAPH
+	self->trans.self.rfcomm.rfcomm_family = AF_BLUETOOTH;
+	bacpy(&self->trans.self.rfcomm.rfcomm_bdaddr, src);
+	self->trans.self.rfcomm.rfcomm_channel = channel;
+#else /*HAVE_BLUETOOTH_NETGRAPH*/
 	self->trans.self.rfcomm.rc_family = AF_BLUETOOTH;
 	bacpy(&self->trans.self.rfcomm.rc_bdaddr, src);
 	self->trans.self.rfcomm.rc_channel = channel;
+#endif /*HAVE_BLUETOOTH_NETGRAPH*/
 #endif /* _WIN32 */
 }
 
@@ -108,9 +128,15 @@
 		return -1;
 	}
 	
+#ifdef HAVE_BLUETOOTH_NETGRAPH
+	if (bind(self->serverfd, (struct sockaddr*) &self->trans.self.rfcomm, 
+		 sizeof(struct sockaddr_rfcomm)))
+	{
+#else /*HAVE_BLUETOOTH_NETGRAPH*/
 	if (bind(self->serverfd, (struct sockaddr*) &self->trans.self.rfcomm, 
 		 sizeof(struct sockaddr_rc)))
 	{
+#endif /*HAVE_BLUETOOTH_NETGRAPH*/
 		DEBUG(0, "Error doing bind\n");
 		goto out_freesock;
 	}
@@ -142,7 +168,11 @@
 int btobex_accept(obex_t *self)
 {
 #ifndef _WIN32
+#ifdef HAVE_BLUETOOTH_NETGRAPH
+	int addrlen = sizeof(struct sockaddr_rfcomm);
+#else /*HAVE_BLUETOOTH_NETGRAPH*/
 	int addrlen = sizeof(struct sockaddr_rc);
+#endif /*HAVE_BLUETOOTH_NETGRAPH*/
 	//int mtu;
 	//int len = sizeof(int);
 
@@ -180,16 +210,26 @@
 			return -1;
 	}
 
+#ifdef HAVE_BLUETOOTH_NETGRAPH
+	ret = bind(self->fd, (struct sockaddr*) &self->trans.self.rfcomm,
+		   sizeof(struct sockaddr_rfcomm));
+#else /*HAVE_BLUETOOTH_NETGRAPH*/
 	ret = bind(self->fd, (struct sockaddr*) &self->trans.self.rfcomm,
 		   sizeof(struct sockaddr_rc));
+#endif /*HAVE_BLUETOOTH_NETGRAPH*/
 
 	if (ret < 0) {
 		DEBUG(4, "ret=%d\n", ret);
 		goto out_freesock;
 	}
 
+#ifdef HAVE_BLUETOOTH_NETGRAPH
+	ret = connect(self->fd, (struct sockaddr*) &self->trans.peer.rfcomm,
+		      sizeof(struct sockaddr_rfcomm));
+#else /*HAVE_BLUETOOTH_NETGRAPH*/
 	ret = connect(self->fd, (struct sockaddr*) &self->trans.peer.rfcomm,
 		      sizeof(struct sockaddr_rc));
+#endif /*HAVE_BLUETOOTH_NETGRAPH*/
 	if (ret < 0) {
 		DEBUG(4, "ret=%d\n", ret);
 		goto out_freesock;
