--- lib/lua/src/usocket.c.orig	2018-09-24 22:09:54 UTC
+++ lib/lua/src/usocket.c
@@ -25,6 +25,7 @@
 #include <unistd.h>
 #include <fcntl.h>
 #include <errno.h>
+#include <netinet/in.h>
 
 #include <stdio.h> // TODO REMOVE
 
