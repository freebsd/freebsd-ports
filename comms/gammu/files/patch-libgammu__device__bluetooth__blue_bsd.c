--- libgammu/device/bluetooth/blue_bsd.c.orig	2016-11-12 10:13:02.619065000 +0800
+++ libgammu/device/bluetooth/blue_bsd.c	2016-11-12 10:13:27.768173000 +0800
@@ -10,6 +10,8 @@
 #ifdef GSM_ENABLE_BLUETOOTHDEVICE
 #ifdef BSD_BLUE_FOUND
 
+#define L2CAP_SOCKET_CHECKED 1
+
 #include <sys/socket.h>
 #include <sys/time.h>
 
