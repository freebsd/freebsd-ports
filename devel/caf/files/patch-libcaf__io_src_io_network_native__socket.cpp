--- libcaf_io/src/io/network/native_socket.cpp.orig	2019-12-27 13:58:36 UTC
+++ libcaf_io/src/io/network/native_socket.cpp
@@ -47,6 +47,7 @@
 #  include <arpa/inet.h>
 #  include <cerrno>
 #  include <fcntl.h>
+#  include <sys/types.h>
 #  include <netinet/in.h>
 #  include <netinet/ip.h>
 #  include <netinet/tcp.h>
