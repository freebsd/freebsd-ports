--- lashd/conn_mgr.c.orig	Sat Jan 13 15:20:55 2007
+++ lashd/conn_mgr.c	Sat Jan 13 15:21:07 2007
@@ -27,6 +27,7 @@
 #include <string.h>
 #include <arpa/inet.h>
 #include <pthread.h>
+#include <fcntl.h>
 
 #include <lash/lash.h>
 #include <lash/internal_headers.h>
