--- ./src/clients/spdsend/server.c.orig	2012-07-11 11:05:05.000000000 +0200
+++ ./src/clients/spdsend/server.c	2013-11-15 08:44:05.105354858 +0100
@@ -33,6 +33,7 @@
 
 #include <errno.h>
 #include <netdb.h>
+#include <sys/types.h>
 #include <netinet/in.h>
 #include <netinet/tcp.h>
 #if USE_THREADS
