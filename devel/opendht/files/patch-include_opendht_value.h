--- include/opendht/value.h.orig	2026-09-04 20:46:41 UTC
+++ include/opendht/value.h
@@ -9,6 +9,11 @@
 
 #include <msgpack.hpp>
 
+#if defined(__FreeBSD__)
+#include <sys/socket.h>
+#include <netinet/in.h>
+#endif
+
 #include <string>
 #include <string_view>
 #include <sstream>
