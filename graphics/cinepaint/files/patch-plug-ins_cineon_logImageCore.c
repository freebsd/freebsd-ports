--- plug-ins/cineon/logImageCore.c.orig	Mon Oct  6 22:48:54 2003
+++ plug-ins/cineon/logImageCore.c	Mon Oct  6 22:49:22 2003
@@ -29,7 +29,6 @@
 #ifdef WIN32
 #include <winsock.h>
 #else
-#include <netinet/in.h>
 #include <sys/param.h>
 #endif
 
