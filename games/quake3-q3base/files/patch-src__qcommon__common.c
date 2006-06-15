--- ./src/qcommon/common.c.orig	Wed Oct  5 19:51:26 2005
+++ ./src/qcommon/common.c	Thu Jun 15 12:03:49 2006
@@ -27,6 +27,7 @@
 #ifdef _WIN32
 #include <winsock.h>
 #else
+#include <sys/types.h>
 #include <netinet/in.h>
 #endif
 
