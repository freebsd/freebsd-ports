--- libcaf_io/src/io/network/ip_endpoint.cpp.orig	2020-04-05 00:36:43 UTC
+++ libcaf_io/src/io/network/ip_endpoint.cpp
@@ -30,6 +30,9 @@
 #  include <ws2tcpip.h>
 #  include <ws2ipdef.h>
 #else
+#  ifdef __FreeBSD__
+#    include <sys/types.h>
+#  endif
 #  include <arpa/inet.h>
 #  include <cerrno>
 #  include <netinet/in.h>
