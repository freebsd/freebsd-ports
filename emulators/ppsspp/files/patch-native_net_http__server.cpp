--- native/net/http_server.cpp.orig	2015-02-23 23:22:58 UTC
+++ native/net/http_server.cpp
@@ -11,6 +11,7 @@
 #include <sys/socket.h>       /*  socket definitions        */
 #include <sys/types.h>        /*  socket types              */
 #include <sys/wait.h>         /*  for waitpid()             */
+#include <netinet/in.h>       /*  struct sockaddr_in        */
 #include <arpa/inet.h>        /*  inet (3) funtions         */
 #include <unistd.h>           /*  misc. UNIX functions      */
 
