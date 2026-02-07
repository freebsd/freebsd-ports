--- mquery.c.orig	2017-11-22 13:47:51 UTC
+++ mquery.c
@@ -10,6 +10,8 @@
 #include <stdlib.h>
 #include <string.h>
 #include <time.h>
+#include <sys/socket.h>
+#include <netinet/in.h>
 
 #include <libmdnsd/mdnsd.h>
 
