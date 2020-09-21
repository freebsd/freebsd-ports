--- tools/irsend.c.orig	2011-03-25 22:28:18 UTC
+++ tools/irsend.c
@@ -41,6 +41,9 @@
 #include <errno.h>
 #include <signal.h>
 #include <limits.h>
+#ifdef __FreeBSD__
+#include <netinet/in.h>
+#endif
 
 #include <stdint.h>
 
