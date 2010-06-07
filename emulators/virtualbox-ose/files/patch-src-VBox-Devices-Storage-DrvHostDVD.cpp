
--- src/VBox/Devices/Storage/DrvHostDVD.cpp.orig	2010-05-20 10:28:06.000000000 +0300
+++ src/VBox/Devices/Storage/DrvHostDVD.cpp	2010-05-20 10:37:47.000000000 +0300
@@ -224,7 +224,7 @@
  */
 static DECLCALLBACK(int) drvHostDvdDoLock(PDRVHOSTBASE pThis, bool fLock)
 {
-#ifdef RT_OS_DARWIN
+#if defined(RT_OS_FREEBSD) || defined(RT_OS_DARWIN)
     uint8_t abCmd[16] =
     {
         SCSI_PREVENT_ALLOW_MEDIUM_REMOVAL, 0, 0, 0, fLock, 0,


