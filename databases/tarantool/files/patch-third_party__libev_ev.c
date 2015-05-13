--- third_party/libev/ev.c.orig	2014-02-19 14:08:58 UTC
+++ third_party/libev/ev.c
@@ -928,12 +928,12 @@ ecb_inline uint64_t ecb_rotr64 (uint64_t
   }
 #endif
 
-#if ECB_GCC_VERSION(4,5)
+#if ECB_GCC_VERSION(4,5) || defined __clang__
   #define ecb_unreachable() __builtin_unreachable ()
 #else
   /* this seems to work fine, but gcc always emits a warning for it :/ */
-  ecb_inline void ecb_unreachable (void) ecb_noreturn;
-  ecb_inline void ecb_unreachable (void) { }
+  ecb_inline ecb_noreturn void ecb_unreachable (void);
+  ecb_inline ecb_noreturn void ecb_unreachable (void) { }
 #endif
 
 /* try to tell the compiler that some condition is definitely true */
@@ -2226,10 +2226,12 @@ ev_recommended_backends (void) EV_THROW
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
