--- core/base/src/TUUID.cxx.orig	2022-11-16 10:35:46 UTC
+++ core/base/src/TUUID.cxx
@@ -140,6 +140,9 @@ system clock catches up.
 #include <sys/sysinfo.h>
 #endif
 #include <ifaddrs.h>
+#ifdef R__FBSD
+#include <sys/socket.h>
+#endif
 #include <netinet/in.h>
 #endif
 #include <chrono>
