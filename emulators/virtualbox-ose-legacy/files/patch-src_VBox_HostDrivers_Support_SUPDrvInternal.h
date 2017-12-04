--- src/VBox/HostDrivers/Support/SUPDrvInternal.h.orig	2016-07-18 11:56:19 UTC
+++ src/VBox/HostDrivers/Support/SUPDrvInternal.h
@@ -235,7 +235,7 @@
 # define SUPDRV_WITHOUT_MSR_PROBER
 #endif
 
-#if 1
+#if 0
 /** @def SUPDRV_USE_TSC_DELTA_THREAD
  * Use a dedicated kernel thread to service TSC-delta measurement requests.
  * @todo Test on servers with many CPUs and sockets. */
