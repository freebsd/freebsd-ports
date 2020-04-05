--- libcaf_io/src/io/network/native_socket.cpp.orig	2020-04-05 00:18:01 UTC
+++ libcaf_io/src/io/network/native_socket.cpp
@@ -44,6 +44,9 @@
 #  include <ws2ipdef.h>
 #  include <ws2tcpip.h>
 #else
+#  ifdef __FreeBSD__
+#    include <sys/types.h>
+#  endif
 #  include <arpa/inet.h>
 #  include <cerrno>
 #  include <fcntl.h>
