--- src/c/clients/spdsend/server.c.orig	2009-12-08 20:16:01.708882022 +0000
+++ src/c/clients/spdsend/server.c	2009-12-08 20:24:49.894019326 +0000
@@ -30,6 +30,7 @@
 
 #include <errno.h>
 #include <netdb.h>
+#include <sys/types.h>
 #include <netinet/in.h>
 #include <netinet/tcp.h>
 #if USE_THREADS
