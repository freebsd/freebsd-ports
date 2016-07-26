--- src/clients/spdsend/server.c.orig	2015-05-07 23:19:02 UTC
+++ src/clients/spdsend/server.c
@@ -33,6 +33,7 @@
 
 #include <errno.h>
 #include <netdb.h>
+#include <sys/types.h>
 #include <netinet/in.h>
 #include <netinet/tcp.h>
 #if USE_THREADS
