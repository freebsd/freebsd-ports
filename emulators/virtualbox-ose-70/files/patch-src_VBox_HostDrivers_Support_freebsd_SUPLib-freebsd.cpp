--- src/VBox/HostDrivers/Support/freebsd/SUPLib-freebsd.cpp.orig	2024-10-10 20:31:28.000000000 +0200
+++ src/VBox/HostDrivers/Support/freebsd/SUPLib-freebsd.cpp	2024-11-17 18:27:46.400938000 +0100
@@ -88,7 +88,7 @@
     /*
      * Try open the BSD device.
      */
-    const char * const *pszDeviceNm = fFlags & SUPR3INIT_F_UNRESTRICTED ? DEVICE_NAME_SYS : DEVICE_NAME_USR;
+    const char * pszDeviceNm = fFlags & SUPR3INIT_F_UNRESTRICTED ? DEVICE_NAME_SYS : DEVICE_NAME_USR;
     int hDevice = open(pszDeviceNm, O_RDWR, 0);
     if (hDevice < 0)
     {
