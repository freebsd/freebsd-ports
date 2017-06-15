--- libgammu/device/bluetooth/blue_bsd.c.orig	2016-12-12 13:47:26 UTC
+++ libgammu/device/bluetooth/blue_bsd.c
@@ -10,6 +10,8 @@
 #ifdef GSM_ENABLE_BLUETOOTHDEVICE
 #ifdef BSD_BLUE_FOUND
 
+#define L2CAP_SOCKET_CHECKED 1
+
 #include <sys/socket.h>
 #include <sys/time.h>
 
