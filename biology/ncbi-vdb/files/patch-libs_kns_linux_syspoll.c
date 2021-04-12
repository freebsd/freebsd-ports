--- libs/kns/linux/syspoll.c.orig	2021-04-12 05:19:32 UTC
+++ libs/kns/linux/syspoll.c
@@ -43,7 +43,7 @@
 #include <unistd.h>
 #include <errno.h>
 
-#include <sys/epoll.h>
+#include <libepoll-shim/sys/epoll.h>
 #include <sys/types.h>
 #include <sys/socket.h>
 
