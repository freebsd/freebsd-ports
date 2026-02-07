--- libev/ev.c.orig	2025-07-21 10:03:33 UTC
+++ libev/ev.c
@@ -511,7 +511,11 @@
 #endif
 
 #if EV_USE_INOTIFY
+# ifdef __FreeBSD__
+# include <sys/mount.h>
+# else
 # include <sys/statfs.h>
+# endif
 # include <sys/inotify.h>
 /* some very old inotify.h headers don't have IN_DONT_FOLLOW */
 # ifndef IN_DONT_FOLLOW
