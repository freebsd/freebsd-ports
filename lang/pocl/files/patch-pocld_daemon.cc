--- pocld/daemon.cc.orig	2025-06-02 18:16:16 UTC
+++ pocld/daemon.cc
@@ -28,6 +28,9 @@
 #include <net/if.h>
 #include <netdb.h>
 #include <netinet/tcp.h>
+#ifdef __FreeBSD__
+#include <netinet/in.h>
+#endif
 #include <numeric>
 #include <random>
 #include <set>
