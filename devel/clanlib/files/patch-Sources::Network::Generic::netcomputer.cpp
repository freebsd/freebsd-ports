--- Sources/Network/Generic/netcomputer.cpp.orig	Thu Jan 22 08:19:24 2004
+++ Sources/Network/Generic/netcomputer.cpp	Thu Jan 22 08:20:01 2004
@@ -19,6 +19,7 @@
 #ifdef WIN32
 #include <winsock2.h>
 #else
+#include <sys/types.h>
 #include <netinet/in.h>
 #endif
 
