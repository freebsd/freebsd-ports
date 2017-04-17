--- src/arvgvinterface.c.orig	2017-04-10 13:30:09 UTC
+++ src/arvgvinterface.c
@@ -38,6 +38,7 @@
 #include <sys/types.h>
 #include <sys/socket.h>
 #include <net/if.h>
+#include <netinet/in.h>
 #include <netdb.h>
 #include <ifaddrs.h>
 #include <stdlib.h>
