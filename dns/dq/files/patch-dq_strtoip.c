--- dq/strtoip.c.orig	2016-11-27 15:38:55 UTC
+++ dq/strtoip.c
@@ -7,6 +7,7 @@ Public domain.
 #include <arpa/inet.h>
 #include "byte.h"
 #include "strtoip.h"
+#include <sys/socket.h>
 
 /* taken from nacl-20110221, from curvecp/curvecpserver.c (public-domain) */
 int strtoip4(unsigned char *ip, const char *x) {
