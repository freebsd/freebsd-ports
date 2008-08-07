--- dns_mre.h.orig	2008-08-02 04:02:47.000000000 +0900
+++ dns_mre.h	2008-08-02 04:02:51.000000000 +0900
@@ -32,6 +32,7 @@
 #include <netdb.h>
 #include <arpa/inet.h>
 #include <string.h>
+#include <time.h>
 
 /* Definitions */
 #define Q_S_PORT	2345	/* Query Source Port */
