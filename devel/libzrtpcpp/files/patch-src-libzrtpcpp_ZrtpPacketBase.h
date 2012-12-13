--- src/libzrtpcpp/ZrtpPacketBase.h	2012-10-17 08:16:16.000000000 -0500
+++ src/libzrtpcpp/ZrtpPacketBase.h	2012-12-13 01:23:58.000000000 -0500
@@ -41,6 +41,7 @@
 #if defined(_MSC_VER) || defined(WIN32) || defined(_WIN32)
 #include <winsock2.h>
 #else
+#include <sys/types.h>
 #include <netinet/in.h>
 #endif
 
