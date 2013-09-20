--- libasync.c	2012-05-14 23:13:13.000000000 -0700
+++ libasync.c	2012-05-14 23:14:27.000000000 -0700
@@ -109,7 +109,7 @@
 #include <sys/fs/vx_ioctl.h>
 #endif
 
-#if defined(OSFV5) || defined(linux)
+#if defined(OSFV5) || defined(linux) || defined(__FreeBSD__)
 #include <string.h>
 #endif
 
@@ -119,7 +119,7 @@
 #include <stdlib.h>
 #endif
 
-#if (defined(solaris) && defined(__LP64__)) || defined(__s390x__) || defined(FreeBSD)
+#if (defined(solaris) && defined(__LP64__)) || defined(__s390x__) || defined(__FreeBSD__)
 /* If we are building for 64-bit Solaris, all functions that return pointers
  * must be declared before they are used; otherwise the compiler will assume
  * that they return ints and the top 32 bits of the pointer will be lost,
