--- meta-server/gnocatan-meta-server.c.orig	Fri Jan 21 17:09:55 2005
+++ meta-server/gnocatan-meta-server.c	Fri Jan 21 17:11:21 2005
@@ -37,6 +37,8 @@
 #include <sys/stat.h>
 #include <netdb.h>
 #include <time.h>
+#include <netinet/in.h>
+#include <sys/socket.h>
 
 #include <glib.h>
 
