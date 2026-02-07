--- libev/ev.c.orig	2024-09-03 13:53:22 UTC
+++ libev/ev.c
@@ -490,7 +490,11 @@
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
@@ -2922,7 +2926,7 @@ ev_recommended_backends (void) EV_NOEXCEPT
 {
   unsigned int flags = ev_supported_backends ();
 
-#ifndef __NetBSD__
+#if !defined(__NetBSD__) && !defined(__FreeBSD__)
   /* kqueue is borked on everything but netbsd apparently */
   /* it usually doesn't work correctly on anything but sockets and pipes */
   flags &= ~EVBACKEND_KQUEUE;
