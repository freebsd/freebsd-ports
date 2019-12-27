--- libcaf_io/src/io/network/ip_endpoint.cpp.orig	2019-12-27 13:50:38 UTC
+++ libcaf_io/src/io/network/ip_endpoint.cpp
@@ -30,6 +30,7 @@
 #  include <ws2tcpip.h>
 #  include <ws2ipdef.h>
 #else
+#  include <sys/types.h>
 #  include <arpa/inet.h>
 #  include <cerrno>
 #  include <netinet/in.h>
