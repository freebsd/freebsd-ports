--- xdebug_com.c.orig	2016-12-28 02:42:57 UTC
+++ xdebug_com.c
@@ -26,6 +26,7 @@
 # include <sys/poll.h>
 # include <unistd.h>
 # include <sys/socket.h>
+# include <netinet/in.h>
 # include <netinet/tcp.h>
 # include <netdb.h>
 #else
