--- src/obex_main.c.orig	Mon Mar 22 18:25:05 2004
+++ src/obex_main.c	Mon Mar 22 18:27:55 2004
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
@@ -79,7 +83,11 @@
 
 #ifdef HAVE_BLUETOOTH
 	if (domain == AF_BLUETOOTH)
+#ifdef HAVE_BLUETOOTH_NETGRAPH
+		proto = BLUETOOTH_PROTO_RFCOMM;
+#else /*HAVE_BLUETOOTH_NETGRAPH*/
 		proto = BTPROTO_RFCOMM;
+#endif /*HAVE_BLUETOOTH_NETGRAPH*/
 #endif /*HAVE_BLUETOOTH*/
 
 	fd = socket(domain, SOCK_STREAM, proto);
