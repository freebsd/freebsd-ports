--- src/obex_transport.h.orig	Mon Mar 22 18:02:08 2004
+++ src/obex_transport.h	Mon Mar 22 18:05:08 2004
@@ -40,8 +40,12 @@
 #include "irda_wrap.h"
 #endif /*HAVE_IRDA*/
 #ifdef HAVE_BLUETOOTH
+#ifdef HAVE_BLUETOOTH_NETGRAPH
+#include <bluetooth.h>
+#else /*HAVE_BLUETOOTH_NETGRAPH*/
 #include <bluetooth/bluetooth.h>
 #include <bluetooth/rfcomm.h>
+#endif /*HAVE_BLUETOOTH_NETGRAPH*/
 #endif /*HAVE_BLUETOOTH*/
 
 #include "obex_main.h"
@@ -52,7 +56,11 @@
 #endif /*HAVE_IRDA*/
 	struct sockaddr_in   inet;
 #ifdef HAVE_BLUETOOTH
+#ifdef HAVE_BLUETOOTH_NETGRAPH
+	struct sockaddr_rfcomm   rfcomm;
+#else /*HAVE_BLUETOOTH_NETGRAPH*/
 	struct sockaddr_rc   rfcomm;
+#endif /*HAVE_BLUETOOTH_NETGRAPH*/
 #endif /*HAVE_BLUETOOTH*/
 } saddr_t;
 
@@ -76,7 +84,4 @@
 int obex_transport_read(obex_t *self, int count, uint8_t *buf, int buflen);
 
 
-#endif OBEX_TRANSPORT_H
-
-
-
+#endif /*OBEX_TRANSPORT_H*/
