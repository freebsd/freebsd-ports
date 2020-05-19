--- src/res_search_async.c.orig	2019-09-28 14:09:47 UTC
+++ src/res_search_async.c
@@ -20,6 +20,7 @@
 #include <sys/types.h>
 #include <sys/socket.h>
 #include <sys/uio.h>
+#include <netinet/in.h>
 #include <arpa/nameser.h>
 #include <netdb.h>
 
