--- third_party/libev/ev.c.orig	2013-09-25 17:14:35.398672102 +0000
+++ third_party/libev/ev.c	2013-09-25 17:15:23.878672738 +0000
@@ -2226,10 +2226,12 @@
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
