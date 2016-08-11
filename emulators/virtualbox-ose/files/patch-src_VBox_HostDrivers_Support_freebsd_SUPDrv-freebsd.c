--- src/VBox/HostDrivers/Support/freebsd/SUPDrv-freebsd.c.orig	2016-07-18 11:56:20 UTC
+++ src/VBox/HostDrivers/Support/freebsd/SUPDrv-freebsd.c
@@ -541,8 +541,7 @@ bool VBOXCALL  supdrvOSGetForcedAsyncTsc
 
 bool VBOXCALL  supdrvOSAreCpusOfflinedOnSuspend(void)
 {
-    /** @todo verify this. */
-    return false;
+    return true;
 }
 
 
