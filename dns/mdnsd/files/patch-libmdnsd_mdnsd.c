--- libmdnsd/mdnsd.c.orig	2017-11-22 13:47:51 UTC
+++ libmdnsd/mdnsd.c
@@ -3,6 +3,8 @@
 #include <string.h>
 #include <stdlib.h>
 #include <errno.h>
+#include <netinet/in.h>
+#include <sys/socket.h>
 
 #define SPRIME 108		/* Size of query/publish hashes */
 #define LPRIME 1009		/* Size of cache hash */
