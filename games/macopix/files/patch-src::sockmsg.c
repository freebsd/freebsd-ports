--- src/sockmsg.c.orig	Tue Sep 28 09:51:53 2004
+++ src/sockmsg.c	Sun Oct 17 23:49:27 2004
@@ -1,5 +1,7 @@
 #include <glib.h>
+#include <sys/types.h>
 #include <sys/socket.h>
+#include <netinet/in.h>
 #include <sys/un.h>
 #include <netdb.h>
 
