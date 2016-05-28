--- include/opendht/value.h.orig	2016-05-13 00:23:45 UTC
+++ include/opendht/value.h
@@ -26,6 +26,11 @@
 
 #include <msgpack.hpp>
 
+#if defined(__FreeBSD__)
+#include <sys/socket.h>
+#include <netinet/in.h>
+#endif
+
 #ifndef _WIN32
 #include <netinet/in.h>
 #include <netdb.h>
