--- app/src/sys/unix/command.c.orig	2020-06-04 10:23:28 UTC
+++ app/src/sys/unix/command.c
@@ -1,5 +1,4 @@
 // for portability
-#define _POSIX_SOURCE // for kill()
 #define _BSD_SOURCE // for readlink()
 
 // modern glibc will complain without this
