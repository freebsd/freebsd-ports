--- src/becker.c.orig	2026-09-26 21:22:23 UTC
+++ src/becker.c
@@ -31,6 +31,7 @@
 #ifndef WINDOWS32
 
 #include <arpa/inet.h>
+#include <netinet/in.h>
 #include <netinet/tcp.h>
 #include <fcntl.h>
 #include <netdb.h>
