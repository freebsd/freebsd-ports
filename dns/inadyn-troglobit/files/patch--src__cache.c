--- ./src/cache.c.orig	2017-09-15 17:41:47.319273722 +0300
+++ ./src/cache.c	2017-09-15 17:41:47.319273722 +0300
@@ -31,6 +31,7 @@
  * once it has read the IP and the modification time.
  */

+#include <netinet/in.h>
 #include <resolv.h>
 #include <sys/stat.h>
 #include <time.h>
