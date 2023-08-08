--- include/opendht/value.h.orig	2022-09-02 21:01:23 UTC
+++ include/opendht/value.h
@@ -26,6 +26,11 @@
 
 #include <msgpack.hpp>
 
+#if defined(__FreeBSD__)
+#include <sys/socket.h>
+#include <netinet/in.h>
+#endif
+
 #include <string>
 #include <string_view>
 #include <sstream>
