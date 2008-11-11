--- src/libpicviz/values-mapping.c.orig	2008-11-08 16:07:44.000000000 +0100
+++ src/libpicviz/values-mapping.c	2008-11-08 16:08:33.000000000 +0100
@@ -24,6 +24,7 @@
 #include <sys/socket.h>
 #include <netdb.h>
 #include <ctype.h>
+#include <netinet/in.h>
 
 
 #if defined(__linux__) && ! defined(__USE_XOPEN)
