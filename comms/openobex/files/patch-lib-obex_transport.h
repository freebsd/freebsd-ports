--- lib/obex_transport.h.orig	Thu May  4 13:24:21 2006
+++ lib/obex_transport.h	Sat Nov 25 22:34:03 2006
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
 #ifdef HAVE_USB
 #include "usbobex.h"
@@ -55,7 +59,11 @@
 #endif /*HAVE_IRDA*/
 	struct sockaddr_in   inet;
 #ifdef HAVE_BLUETOOTH
+#ifdef HAVE_BLUETOOTH_NETGRAPH
+	struct sockaddr_rfcomm   rfcomm;
+#else /*HAVE_BLUETOOTH_NETGRAPH*/
 	struct sockaddr_rc   rfcomm;
+#endif /*HAVE_BLUETOOTH_NETGRAPH*/
 #endif /*HAVE_BLUETOOTH*/
 #ifdef HAVE_USB
 	struct obex_usb_intf_transport_t usb;
