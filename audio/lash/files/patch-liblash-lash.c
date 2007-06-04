--- liblash/lash.c.orig	Tue May 22 20:13:00 2007
+++ liblash/lash.c	Tue May 22 20:13:13 2007
@@ -23,6 +23,8 @@
 #include <strings.h>
 #include <pthread.h>
 #include <sys/types.h>
+#include <sys/time.h>
+#include <sys/resource.h>
 #include <sys/wait.h>
 #include <sys/socket.h>
 #include <netdb.h>
