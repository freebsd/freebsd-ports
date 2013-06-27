--- ./src/update.c.orig	2012-01-29 20:34:57.429446671 +0000
+++ ./src/update.c	2012-01-29 20:35:29.991443641 +0000
@@ -31,6 +31,7 @@
 
 #include <stdio.h>
 #include <string.h>
+#include <netinet/in.h>
 
 #ifndef WIN32
 #   include <sys/socket.h>
