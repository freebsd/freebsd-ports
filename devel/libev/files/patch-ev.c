--- ev.c.orig	2020-03-18 12:27:32 UTC
+++ ev.c
@@ -507,7 +507,11 @@
 #endif
 
 #if EV_USE_INOTIFY
-# include <sys/statfs.h>
+# ifdef __FreeBSD__
+#  include <sys/mount.h>
+# else
+#  include <sys/statfs.h>
+# endif
 # include <sys/inotify.h>
 /* some very old inotify.h headers don't have IN_DONT_FOLLOW */
 # ifndef IN_DONT_FOLLOW
@@ -3149,7 +3153,7 @@ ev_recommended_backends (void) EV_NOEXCEPT
 {
   unsigned int flags = ev_supported_backends ();
 
-#ifndef __NetBSD__
+#if !defined(__NetBSD__) && !defined(__FreeBSD__)
   /* kqueue is borked on everything but netbsd apparently */
   /* it usually doesn't work correctly on anything but sockets and pipes */
   flags &= ~EVBACKEND_KQUEUE;
