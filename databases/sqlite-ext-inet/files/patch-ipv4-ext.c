--- ipv4-ext.c.orig	2009-07-30 17:21:45.000000000 +0400
+++ ipv4-ext.c	2009-07-30 17:22:19.000000000 +0400
@@ -355,6 +355,7 @@
 
 #include <stdlib.h>
 #include <sys/types.h>
+#include <sys/socket.h>
 #include <string.h>
 #include <arpa/inet.h>
 #include <stdio.h>
