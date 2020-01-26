--- orc/orccpu-powerpc.c.orig	2019-09-09 07:21:43 UTC
+++ orc/orccpu-powerpc.c
@@ -55,6 +55,7 @@
 #endif
 
 #if defined(__FreeBSD__) || defined(__APPLE__)
+#include <stdio.h>
 #include <sys/types.h>
 #include <sys/sysctl.h>
 #endif
