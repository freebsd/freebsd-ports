--- src/init.c.orig	2016-05-20 11:41:06 UTC
+++ src/init.c
@@ -39,6 +39,9 @@
 #include <unistd.h>
 #include <errno.h>
 #include <stdlib.h>
+#if defined(__OpenBSD__) || defined(__FreeBSD__) || defined(__NetBSD__) || defined(__DragonFly__)
+#include <signal.h>
+#endif
 
 #define LINESZ 1024
 
