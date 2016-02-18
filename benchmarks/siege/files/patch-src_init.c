--- src/init.c.orig	2015-12-22 20:12:40 UTC
+++ src/init.c
@@ -35,6 +35,9 @@
 #include <unistd.h>
 #include <errno.h>
 #include <stdlib.h>
+#if defined(__OpenBSD__) || defined(__FreeBSD__) || defined(__NetBSD__) || defined(__DragonFly__)
+#include <signal.h>
+#endif
 
 int
 init_config( void )
