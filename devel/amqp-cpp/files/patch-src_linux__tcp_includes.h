--- src/linux_tcp/includes.h.orig	2019-04-24 08:29:32 UTC
+++ src/linux_tcp/includes.h
@@ -14,6 +14,7 @@
 #include <sys/socket.h>
 #include <netdb.h>
 #include <unistd.h>
+#include <netinet/in.h>
 #include <netinet/tcp.h>
 
 // utility classes
