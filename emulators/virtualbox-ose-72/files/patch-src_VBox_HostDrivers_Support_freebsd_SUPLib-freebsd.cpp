--- src/VBox/HostDrivers/Support/freebsd/SUPLib-freebsd.cpp.orig	2025-08-13 19:51:09 UTC
+++ src/VBox/HostDrivers/Support/freebsd/SUPLib-freebsd.cpp
@@ -88,7 +88,7 @@ DECLHIDDEN(int) suplibOsInit(PSUPLIBDATA pThis, bool f
     /*
      * Try open the BSD device.
      */
-    const char * const *pszDeviceNm = fFlags & SUPR3INIT_F_UNRESTRICTED ? DEVICE_NAME_SYS : DEVICE_NAME_USR;
+    const char * pszDeviceNm = fFlags & SUPR3INIT_F_UNRESTRICTED ? DEVICE_NAME_SYS : DEVICE_NAME_USR;
     int hDevice = open(pszDeviceNm, O_RDWR, 0);
     if (hDevice < 0)
     {
