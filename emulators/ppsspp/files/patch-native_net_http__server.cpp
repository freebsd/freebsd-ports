--- native/net/http_server.cpp.orig	2015-02-23 23:22:58 UTC
+++ native/net/http_server.cpp
@@ -12,6 +12,7 @@
 #include <sys/types.h>        /*  socket types              */
 #include <sys/wait.h>         /*  for waitpid()             */
 #include <arpa/inet.h>        /*  inet (3) funtions         */
+#include <netinet/in.h>       /*  struct sockaddr_in        */
 #include <unistd.h>           /*  misc. UNIX functions      */
 
 #endif
