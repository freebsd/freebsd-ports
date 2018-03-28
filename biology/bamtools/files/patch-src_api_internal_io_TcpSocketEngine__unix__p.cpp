--- src/api/internal/io/TcpSocketEngine_unix_p.cpp.orig	2015-06-16 16:50:53 UTC
+++ src/api/internal/io/TcpSocketEngine_unix_p.cpp
@@ -12,6 +12,8 @@
 using namespace BamTools;
 using namespace BamTools::Internal;
 
+#include <netinet/in.h>
+
 #ifdef SUN_OS
 #include <sys/filio.h> 
 #endif
