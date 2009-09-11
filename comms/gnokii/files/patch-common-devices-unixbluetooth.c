--- common/devices/unixbluetooth.c.orig	2009-06-23 20:24:56.000000000 +0200
+++ common/devices/unixbluetooth.c	2009-09-08 22:21:31.450731259 +0200
@@ -51,7 +51,7 @@
 #ifdef HAVE_BLUETOOTH_NETGRAPH	/* FreeBSD / netgraph */
 
 #include <bluetooth.h>
-#include <sdp.h>
+#include </usr/include/sdp.h>
 
 #define BTPROTO_RFCOMM BLUETOOTH_PROTO_RFCOMM
 #define BDADDR_ANY NG_HCI_BDADDR_ANY
@@ -66,7 +66,7 @@
 #ifdef HAVE_BLUETOOTH_NETBT	/* FreeBSD / netbt */
 
 #include <bluetooth.h>
-#include <sdp.h> 
+#include </usr/include/sdp.h> 
 
 #define GNOKII_SERIAL_PORT_CLASS	SDP_SERVICE_CLASS_SERIAL_PORT
 #define GNOKII_DIALUP_NETWORK_CLASS	SDP_SERVICE_CLASS_DIALUP_NETWORKING
