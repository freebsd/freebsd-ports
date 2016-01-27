--- src/nslookup.c.orig	2016-01-23 20:44:53 UTC
+++ src/nslookup.c
@@ -8,6 +8,8 @@ const char *inet_ntop(int af, const void
 #else
 #include <netdb.h>
 #include <arpa/inet.h>
+#include <sys/socket.h>
+#include <netinet/in.h>
 #endif
 
 SEXP R_nslookup(SEXP hostname) {
