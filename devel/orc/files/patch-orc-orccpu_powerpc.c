--- orc/orccpu-powerpc.c.orig	2010-04-24 22:48:59.000000000 +0200
+++ orc/orccpu-powerpc.c	2010-04-24 22:49:17.000000000 +0200
@@ -46,6 +46,7 @@
 #endif
 
 #if defined(__FreeBSD__) || defined(__APPLE__)
+#include <stdio.h>
 #include <sys/types.h>
 #include <sys/sysctl.h>
 #endif

