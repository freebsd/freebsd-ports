diff -ur /usr/Arch/Nokia/Gammu/gammu-0.90.0/common/device/bluetoth/bluetoth.c ./common/device/bluetoth/bluetoth.c
--- /usr/Arch/Nokia/Gammu/gammu-0.90.0/common/device/bluetoth/bluetoth.c	Sun Nov  2 11:43:28 2003
+++ ./common/device/bluetoth/bluetoth.c	Tue Dec  9 17:19:59 2003
@@ -11,11 +11,10 @@
 #include <string.h>
 
 #ifndef WIN32
-#  include <sys/socket.h>
-#  include <sys/time.h>
-#  include <unistd.h>
-#  include <bluetooth/bluetooth.h>
-#  include <bluetooth/rfcomm.h>
+#include <sys/socket.h>
+#include <sys/time.h>
+#include <unistd.h>
+#include <bluetooth.h>
 #else
 #  include <windows.h>
 #  include <io.h>
@@ -25,6 +24,11 @@
 #include "../devfunc.h"
 #include "bluetoth.h"
 
+#define BTPROTO_RFCOMM BLUETOOTH_PROTO_RFCOMM
+#define BDADDR_ANY NG_HCI_BDADDR_ANY
+
+#undef WIN32
+
 #ifdef WIN32
 static GSM_Error bluetooth_connect(GSM_StateMachine *s, int port)
 {
@@ -80,7 +84,7 @@
 static GSM_Error bluetooth_connect(GSM_StateMachine *s, int port)
 {
 	GSM_Device_BlueToothData 	*d = &s->Device.Data.BlueTooth;
-	struct sockaddr_rc 		laddr, raddr;
+	struct sockaddr_rfcomm 		laddr, raddr;
 	bdaddr_t			bdaddr;
 	int 				fd;
 
@@ -89,9 +93,9 @@
 		return GE_DEVICENODRIVER;
 	}
 
-	bacpy(&laddr.rc_bdaddr, BDADDR_ANY);
-	laddr.rc_family 	= AF_BLUETOOTH;
-	laddr.rc_channel 	= 0;
+	bacpy(&laddr.rfcomm_bdaddr, BDADDR_ANY);
+	laddr.rfcomm_family 	= AF_BLUETOOTH;
+	laddr.rfcomm_channel 	= 0;
 
 	if (bind(fd, (struct sockaddr *)&laddr, sizeof(laddr)) < 0) {
 		dbgprintf("Can't bind socket\n");
@@ -100,9 +104,9 @@
 	}
 
 	str2ba(s->CurrentConfig->Device, &bdaddr);
-	bacpy(&raddr.rc_bdaddr, &bdaddr);
-	raddr.rc_family 	= AF_BLUETOOTH;
-	raddr.rc_channel 	= port;
+	bacpy(&raddr.rfcomm_bdaddr, &bdaddr);
+	raddr.rfcomm_family 	= AF_BLUETOOTH;
+	raddr.rfcomm_channel 	= port;
 
 	if (connect(fd, (struct sockaddr *)&raddr, sizeof(raddr)) < 0) {
 		dbgprintf("Can't connect\n");
