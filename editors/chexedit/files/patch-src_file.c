--- src/file.c.orig	Wed Jun 30 05:57:15 1999
+++ src/file.c	Sat Mar 17 22:23:57 2001
@@ -19,6 +19,7 @@
 #include <dirent.h>
 #endif
 
+#include <sys/types.h>
 #include <grp.h>
 #include <pwd.h>
 
@@ -618,8 +619,8 @@
 
          wprintw (Globals.wmain,
    /* why does it seem like on OpenBSD this is broken? */
-#if defined(__OpenBSD__) || defined(BROKEN)
-            "%s %-8s %-8s %10ld %1d\b2d-%02d-%02d %02d:%02d ",
+#if defined(__OpenBSD__) || defined(__FreeBSD__) || defined(BROKEN)
+            "%s %-8s %-8s %10ld %1d\b%04d-%02d-%02d %02d:%02d ",
 #else
             "%s %-8s %-8s %10ld %d-%02d-%02d %02d:%02d ",
 #endif
