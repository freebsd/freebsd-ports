--- ./ev.c.orig	2011-02-09 00:17:37.000000000 +0100
+++ ./ev.c	2011-08-19 17:01:35.000000000 +0200
@@ -967,8 +967,8 @@
   #define ecb_unreachable() __builtin_unreachable ()
 #else
   /* this seems to work fine, but gcc always emits a warning for it :/ */
-  ecb_inline void ecb_unreachable (void) ecb_noreturn;
-  ecb_inline void ecb_unreachable (void) { }
+  ecb_inline ecb_noreturn void ecb_unreachable (void);
+  ecb_inline ecb_noreturn void ecb_unreachable (void) { }
 #endif
 
 /* try to tell the compiler that some condition is definitely true */
@@ -2443,10 +2443,12 @@
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
