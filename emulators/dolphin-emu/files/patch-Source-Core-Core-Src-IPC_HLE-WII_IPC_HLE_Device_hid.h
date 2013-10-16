--- Source/Core/Core/Src/IPC_HLE/WII_IPC_HLE_Device_hid.h.orig	2013-09-17 16:44:46.000000000 +0200
+++ Source/Core/Core/Src/IPC_HLE/WII_IPC_HLE_Device_hid.h	2013-09-17 16:48:22.000000000 +0200
@@ -16,6 +16,10 @@
 
 #define HIDERR_NO_DEVICE_FOUND -4
 
+#if defined __FreeBSD__
+#define LIBUSB_CALL
+#endif
+
 /* Connection timed out */
 
 class CWII_IPC_HLE_Device_hid : public IWII_IPC_HLE_Device
