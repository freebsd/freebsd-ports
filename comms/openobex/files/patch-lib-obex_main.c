--- lib/obex_main.c.orig	Thu May  4 13:24:21 2006
+++ lib/obex_main.c	Sat Nov 25 22:32:59 2006
@@ -46,7 +46,11 @@
 #include <stdio.h>
 
 #ifdef HAVE_BLUETOOTH
+#ifdef HAVE_BLUETOOTH_NETGRAPH
+#include <bluetooth.h>
+#else /*HAVE_BLUETOOTH_NETGRAPH*/
 #include <bluetooth/bluetooth.h>
+#endif /*HAVE_BLUETOOTH_NETGRAPH*/
 #endif /*HAVE_BLUETOOTH*/
 
 #endif /* _WIN32 */
@@ -80,7 +84,11 @@
 
 #ifdef HAVE_BLUETOOTH
 	if (domain == AF_BLUETOOTH)
+#ifdef HAVE_BLUETOOTH_NETGRAPH
+		proto = BLUETOOTH_PROTO_RFCOMM;
+#else /*HAVE_BLUETOOTH_NETGRAPH*/
 		proto = BTPROTO_RFCOMM;
+#endif /*HAVE_BLUETOOTH_NETGRAPH*/
 #endif /*HAVE_BLUETOOTH*/
 
 	fd = socket(domain, SOCK_STREAM, proto);
