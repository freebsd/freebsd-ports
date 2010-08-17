--- ev.c.orig  2010-08-16 08:33:48.667681306 +0200
+++ ev.c       2010-08-16 08:33:51.449982136 +0200
@@ -1470,10 +1470,12 @@
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
