--- libdesklets/system/gtop.c.orig	2008-03-20 08:00:58.000000000 +0900
+++ libdesklets/system/gtop.c	2009-12-23 01:21:26.000000000 +0900
@@ -30,6 +30,7 @@
 
 #include <sys/types.h>
 #include <sys/socket.h>
+#include <netinet/in.h>
 #include <arpa/inet.h>
 
 
