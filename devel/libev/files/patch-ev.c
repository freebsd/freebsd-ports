--- ./ev.c.orig	2011-02-09 00:17:37.000000000 +0100
+++ ./ev.c	2011-08-19 17:01:35.000000000 +0200
@@ -1591,10 +1591,12 @@
   unsigned int flags = ev_supported_backends ();
 
 #ifndef __NetBSD__
+#ifndef __FreeBSD__
   /* kqueue is borked on everything but netbsd apparently */
   /* it usually doesn't work correctly on anything but sockets and pipes */
   flags &= ~EVBACKEND_KQUEUE;
 #endif
+#endif
 #ifdef __APPLE__
   /* only select works correctly on that "unix-certified" platform */
   flags &= ~EVBACKEND_KQUEUE; /* horribly broken, even for sockets */
