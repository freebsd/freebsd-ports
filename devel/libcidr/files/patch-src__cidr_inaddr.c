--- ./src/cidr_inaddr.c.orig	2012-04-01 00:29:13.000000000 -0400
+++ ./src/cidr_inaddr.c	2012-04-01 00:29:27.000000000 -0400
@@ -5,6 +5,7 @@
 #include <errno.h>
 #include <stdlib.h>
 #include <string.h>
+#include <arpa/inet.h>
 /* netinet/in.h is pulled in by libcidr.h */
 
 #include <libcidr.h>
