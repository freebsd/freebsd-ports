--- include/opendht/value.h.orig	2016-11-12 22:38:27 UTC
+++ include/opendht/value.h
@@ -26,6 +26,11 @@
 
 #include <msgpack.hpp>
 
+#if defined(__FreeBSD__)
+#include <sys/socket.h>
+#include <netinet/in.h>
+#endif
+
 #include <string>
 #include <sstream>
 #include <bitset>
