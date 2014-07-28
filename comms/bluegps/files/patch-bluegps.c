--- bluegps.c  2006-06-26 20:28:31.000000000 +0200
+++ bluegps.c  2007-07-29 18:54:17.000000000 +0200
@@ -27,10 +27,21 @@
 #include <stdarg.h>
 #include <ctype.h>
 
+#ifdef __FreeBSD__
+#include <string.h>
+#include <sys/types.h>
+#include <sys/socket.h>
+#else
 #include <netinet/ip.h>
+#endif
 
+
+#ifdef __FreeBSD__
+#include <bluetooth.h>
+#else
 #include <bluetooth/bluetooth.h>
 #include <bluetooth/rfcomm.h>
+#endif
 
 #include "rbt3000.h"
 
@@ -269,19 +280,44 @@
 int
 rbt3000_connect (char *device_addr)
 {
-
+#ifdef __FreeBSD__
+  struct sockaddr_rfcomm rem_addr;
+  struct hostent * he;
+
+  memset(&rem_addr, 0, sizeof(rem_addr));
+  rem_addr.rfcomm_len = sizeof(rem_addr);
+  rem_addr.rfcomm_family = AF_BLUETOOTH;
+  rem_addr.rfcomm_channel = RFCOMM_CHANNEL;
+
+  if ((he = bt_gethostbyname(device_addr))) {
+      context->device = *(bdaddr_t *) he->h_addr_list[0];
+      if (context->messages == MSG_VERBOSE) 
+              printf("Actual BT address for '%s': %s\n",
+                      device_addr, bt_ntoa(&(context->device),NULL));
+  } else
+  if (!bt_aton(device_addr, &context->device)) {
+      perror("No such device address");
+      return 0;
+  }
+  rem_addr.rfcomm_bdaddr = context->device;
+#else 
   struct sockaddr_rc rem_addr;
 
-  baswap (&context->device, strtoba (device_addr));
-
   rem_addr.rc_family  = AF_BLUETOOTH;
-  rem_addr.rc_bdaddr  = context->device;
   rem_addr.rc_channel = RFCOMM_CHANNEL;
+  baswap (&context->device, strtoba (device_addr));
+  rem_addr.rc_bdaddr  = context->device;
+#endif
 
   /* bluez connects to BlueClient */
   if ((context->device_fd = socket (PF_BLUETOOTH,
                                     SOCK_STREAM,
-                                    BTPROTO_RFCOMM)) < 0 )
+#ifdef __FreeBSD__
+                                  BLUETOOTH_PROTO_RFCOMM
+#else
+                                    BTPROTO_RFCOMM
+#endif
+              )) < 0 )
     {
       perror ("Can't create socket");
       return 0;
