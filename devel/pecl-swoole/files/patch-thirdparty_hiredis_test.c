--- thirdparty/hiredis/test.c.orig	2018-11-22 23:09:25 UTC
+++ thirdparty/hiredis/test.c
@@ -4,6 +4,7 @@
 #include <string.h>
 #include <strings.h>
 #include <sys/time.h>
+#include <sys/socket.h>
 #include <netdb.h>
 #include <assert.h>
 #include <unistd.h>
