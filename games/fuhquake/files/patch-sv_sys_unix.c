--- sv_sys_unix.c.orig	Wed May 21 17:18:37 2003
+++ sv_sys_unix.c	Wed May 21 15:09:31 2003
@@ -24,7 +24,7 @@
 #include <libc.h>
 #endif
 
-#if defined(__linux__) || defined(sun)
+#if defined(__linux__) || defined(__FreeBSD__) || defined(sun)
 #include <sys/stat.h>
 #include <unistd.h>
 #include <sys/time.h>
