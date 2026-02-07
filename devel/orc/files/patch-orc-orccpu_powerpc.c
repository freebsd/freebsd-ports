--- orc/orccpu-powerpc.c.orig	2023-05-31 21:29:36 UTC
+++ orc/orccpu-powerpc.c
@@ -55,6 +55,7 @@
 #endif
 
 #if defined(__FreeBSD__) || defined(__APPLE__) || defined(__NetBSD__)
+#include <stdio.h>
 #include <sys/types.h>
 #include <sys/sysctl.h>
 #endif
