- Fix INVARIANTS warning:
acquiring duplicate lock of same type: "IPRT Fast Mutex Semaphore"

Submitted by:	avg
--- src/VBox/Runtime/r0drv/freebsd/semfastmutex-r0drv-freebsd.c.orig	2011-11-04 12:19:54.000000000 +0100
+++ src/VBox/Runtime/r0drv/freebsd/semfastmutex-r0drv-freebsd.c	2011-12-06 23:12:49.233297685 +0100
@@ -66,7 +66,7 @@
     if (pThis)
     {
         pThis->u32Magic = RTSEMFASTMUTEX_MAGIC;
-        sx_init(&pThis->SxLock, "IPRT Fast Mutex Semaphore");
+        sx_init_flags(&pThis->SxLock, "IPRT Fast Mutex Semaphore", SX_DUPOK);
 
         *phFastMtx = pThis;
         return VINF_SUCCESS;
