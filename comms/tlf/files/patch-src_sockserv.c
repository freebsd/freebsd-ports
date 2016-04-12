--- src/sockserv.c.orig	2016-01-16 17:45:20 UTC
+++ src/sockserv.c
@@ -23,6 +23,8 @@
 /* Written by N2RJT - Dave Brown */
 
 
+#include <sys/socket.h>
+#include <netinet/in.h>
 #include <errno.h>
 #include <netdb.h>
 #include <stdio.h>
