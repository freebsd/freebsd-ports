--- src/VBox/Runtime/r0drv/freebsd/sleepqueue-r0drv-freebsd.h.orig	2011-05-16 18:33:52.000000000 +0200
+++ src/VBox/Runtime/r0drv/freebsd/sleepqueue-r0drv-freebsd.h	2011-06-02 18:26:49.000000000 +0200
@@ -313,7 +313,9 @@
 {
     sleepq_lock(pvWaitChan);
     sleepq_broadcast(pvWaitChan, SLEEPQ_CONDVAR, 0, 0);
+#if __FreeBSD_version >= 800000 /* Broadcast releases the sleep queue lock on FreeBSD 7.x */
     sleepq_release(pvWaitChan);
+#endif
 }
 
 /**
