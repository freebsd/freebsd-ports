--- ./src/cache.c.orig	2017-09-15 14:41:47 UTC
+++ ./src/cache.c
@@ -31,6 +31,7 @@
  * once it has read the IP and the modification time.
  */

+#include <netinet/in.h>
 #include <resolv.h>
 #include <sys/stat.h>
 #include <time.h>
