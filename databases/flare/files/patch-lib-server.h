--- src/lib/server.h.orig	2009-10-09 19:08:47.000000000 +0900
+++ src/lib/server.h	2010-05-29 10:10:05.713330772 +0900
@@ -10,9 +10,9 @@
 
 #include "config.h"
 
+#include <sys/types.h>
 #include <netinet/tcp.h>
 #include <sys/un.h>
-#include <sys/types.h>
 #include <sys/stat.h>
 
 #ifdef HAVE_EPOLL
