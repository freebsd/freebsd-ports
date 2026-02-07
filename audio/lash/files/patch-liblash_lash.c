--- liblash/lash.c.orig	2007-03-09 15:34:40 UTC
+++ liblash/lash.c
@@ -23,6 +23,8 @@
 #include <strings.h>
 #include <pthread.h>
 #include <sys/types.h>
+#include <sys/time.h>
+#include <sys/resource.h>
 #include <sys/wait.h>
 #include <sys/socket.h>
 #include <netdb.h>
