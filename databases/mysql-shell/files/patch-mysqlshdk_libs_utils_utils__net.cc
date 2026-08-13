--- mysqlshdk/libs/utils/utils_net.cc.orig	2026-01-26 17:10:16 UTC
+++ mysqlshdk/libs/utils/utils_net.cc
@@ -25,6 +25,10 @@
 
 #include "mysqlshdk/libs/utils/utils_net.h"
 
+#ifdef __FreeBSD__
+#include <netinet/in.h>
+#endif
+
 #ifdef _WIN32
 // clang-format off
 #include <WinSock2.h>
