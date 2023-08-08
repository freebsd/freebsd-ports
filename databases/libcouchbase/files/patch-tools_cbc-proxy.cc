--- tools/cbc-proxy.cc.orig	2022-12-09 14:19:12 UTC
+++ tools/cbc-proxy.cc
@@ -35,6 +35,10 @@
 #include <event2/bufferevent.h>
 #include <event2/buffer.h>
 
+#ifdef __FreeBSD__
+#include <netinet/in.h>
+#endif
+
 using namespace cbc;
 using namespace cliopts;
 
