--- Sources/Network/Generic/browse_client_generic.cpp.orig	Thu Jan 22 08:20:26 2004
+++ Sources/Network/Generic/browse_client_generic.cpp	Thu Jan 22 08:20:37 2004
@@ -17,6 +17,7 @@
 #pragma warning (disable:4355)
 #include <winsock2.h> // needed for ntohl and ntohs
 #else
+#include <sys/types.h>
 #include <netinet/in.h>
 #endif
 
