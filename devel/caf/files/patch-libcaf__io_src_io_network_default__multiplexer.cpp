--- libcaf_io/src/io/network/default_multiplexer.cpp.orig	2020-04-05 00:30:36 UTC
+++ libcaf_io/src/io/network/default_multiplexer.cpp
@@ -59,6 +59,9 @@
 #  include <ws2ipdef.h>
 #  include <ws2tcpip.h>
 #else
+#  ifdef __FreeBSD__
+#    include <sys/types.h>
+#  endif
 #  include <arpa/inet.h>
 #  include <cerrno>
 #  include <fcntl.h>
