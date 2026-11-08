--- orc/orccpu-powerpc.c.orig	2026-08-28 18:57:31 UTC
+++ orc/orccpu-powerpc.c
@@ -58,6 +58,7 @@
 #endif
 
 #if defined(__APPLE__) || defined(__FreeBSD__) || defined(__NetBSD__)
+#include <stdio.h>
 #include <sys/types.h>
 #include <sys/sysctl.h>
 #endif
