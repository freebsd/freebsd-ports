--- libgammu/device/bluetoth/bluez.c.orig	2015-12-08 10:38:12 UTC
+++ libgammu/device/bluetoth/bluez.c
@@ -23,6 +23,8 @@
 #ifdef GSM_ENABLE_BLUETOOTHDEVICE
 #ifdef BLUEZ_FOUND
 
+#define BDADDR_ANY NG_HCI_BDADDR_ANY
+
 #include <stdlib.h>
 #include <stdio.h>
 #include <fcntl.h>
@@ -31,11 +33,7 @@
 #include <sys/socket.h>
 #include <sys/time.h>
 #include <unistd.h>
-#include <bluetooth/bluetooth.h>
-#include <bluetooth/rfcomm.h>
-#include <bluetooth/sdp.h>
-#include <bluetooth/sdp_lib.h>
-#include <bluetooth/hci_lib.h>
+#include <bluetooth.h>
 
 #include "../../gsmcomon.h"
 #include "../devfunc.h"
@@ -48,7 +46,7 @@ GSM_Error bluetooth_connect(GSM_StateMac
 	/* Some phones need time till they are accessible after SDP browsing */
 	for (tries = 0; tries < 5; tries++) {
 		GSM_Device_BlueToothData 	*d = &s->Device.Data.BlueTooth;
-		struct sockaddr_rc 		laddr, raddr;
+		struct sockaddr_rfcomm 		laddr, raddr;
 		bdaddr_t			bdaddr;
 		int 				fd;
 
@@ -61,15 +59,15 @@ GSM_Error bluetooth_connect(GSM_StateMac
 
 		smprintf(s, "Connecting to RF channel %i\n", port);
 
-		fd = socket(PF_BLUETOOTH, SOCK_STREAM, BTPROTO_RFCOMM);
+		fd = socket(PF_BLUETOOTH, SOCK_STREAM, BLUETOOTH_PROTO_RFCOMM);
 		if (fd < 0) {
 			smprintf(s, "Can't create socket\n");
 			continue;
 		}
 
-		bacpy(&laddr.rc_bdaddr, BDADDR_ANY);
-		laddr.rc_family 	= AF_BLUETOOTH;
-		laddr.rc_channel 	= 0;
+		bacpy(&laddr.rfcomm_bdaddr, BDADDR_ANY);
+		laddr.rfcomm_family 	= AF_BLUETOOTH;
+		laddr.rfcomm_channel 	= 0;
 
 		if (bind(fd, (struct sockaddr *)&laddr, sizeof(laddr)) < 0) {
 			smprintf(s, "Can't bind socket (%d, %s)\n", errno, strerror(errno));
@@ -78,9 +76,9 @@ GSM_Error bluetooth_connect(GSM_StateMac
 		}
 
 		str2ba(device, &bdaddr);
-		bacpy(&raddr.rc_bdaddr, &bdaddr);
-		raddr.rc_family = AF_BLUETOOTH;
-		raddr.rc_channel = port;
+		bacpy(&raddr.rfcomm_bdaddr, &bdaddr);
+		raddr.rfcomm_family = AF_BLUETOOTH;
+		raddr.rfcomm_channel = port;
 
 		if (connect(fd, (struct sockaddr *)&raddr, sizeof(raddr)) < 0) {
 			smprintf(s, "Can't connect (%d, %s)\n", errno, strerror(errno));
