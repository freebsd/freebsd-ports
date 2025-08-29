--- src/VBox/HostDrivers/Support/SUPDrvInternal.h.orig	2021-01-07 15:41:25 UTC
+++ src/VBox/HostDrivers/Support/SUPDrvInternal.h
@@ -217,7 +217,7 @@
 # define SUPDRV_WITHOUT_MSR_PROBER
 #endif
 
-#if 1
+#if 0
 /** @def SUPDRV_USE_TSC_DELTA_THREAD
  * Use a dedicated kernel thread to service TSC-delta measurement requests.
  * @todo Test on servers with many CPUs and sockets. */
