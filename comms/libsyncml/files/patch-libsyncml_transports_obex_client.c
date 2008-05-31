--- libsyncml/transports/obex_client.c.orig	2007-10-16 15:25:31.000000000 +0200
+++ libsyncml/transports/obex_client.c	2008-03-09 22:32:06.000000000 +0100
@@ -26,7 +26,13 @@
 #include <libsyncml/sml_transport_internals.h>
 
 #ifdef ENABLE_BLUETOOTH
+#ifdef HAVE_BLUETOOTH_BLUETOOTH_H
 #include <bluetooth/bluetooth.h>
+#else
+#define COMPAT_BLUEZ
+#include <bluetooth.h>
+#define BDADDR_ANY NG_HCI_BDADDR_ANY
+#endif
 #endif
 
 #include "obex_client.h"
