--- ev.c.orig	2015-12-20 21:12:53 UTC
+++ ev.c
@@ -2736,7 +2736,7 @@ ev_recommended_backends (void) EV_THROW
 {
   unsigned int flags = ev_supported_backends ();
 
-#ifndef __NetBSD__
+#if !defined(__NetBSD__) && !defined(__FreeBSD__)
   /* kqueue is borked on everything but netbsd apparently */
   /* it usually doesn't work correctly on anything but sockets and pipes */
   flags &= ~EVBACKEND_KQUEUE;
