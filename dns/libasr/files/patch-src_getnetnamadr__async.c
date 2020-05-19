--- src/getnetnamadr_async.c.orig	2019-09-28 14:09:47 UTC
+++ src/getnetnamadr_async.c
@@ -19,6 +19,7 @@
 
 #include <sys/types.h>
 #include <sys/socket.h>
+#include <netinet/in.h>
 #include <arpa/inet.h>
 #include <arpa/nameser.h>
 #include <netdb.h>
