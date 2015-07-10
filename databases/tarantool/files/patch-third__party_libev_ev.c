--- third_party/libev/ev.c.orig	2015-07-10 10:15:23 UTC
+++ third_party/libev/ev.c
@@ -2225,7 +2225,7 @@ ev_recommended_backends (void) EV_THROW
 {
   unsigned int flags = ev_supported_backends ();
 
-#if !defined(__NetBSD__) && !defined(__FreeBSD__)
+#if !defined(__NetBSD__)
   /* kqueue is borked on everything but netbsd apparently */
   /* it usually doesn't work correctly on anything but sockets and pipes */
   flags &= ~EVBACKEND_KQUEUE;
