--- libcaf_io/src/io/network/default_multiplexer.cpp.orig	2019-12-27 13:41:05 UTC
+++ libcaf_io/src/io/network/default_multiplexer.cpp
@@ -63,11 +63,11 @@
 #  include <cerrno>
 #  include <fcntl.h>
 #  include <netdb.h>
+#  include <sys/types.h>
 #  include <netinet/in.h>
 #  include <netinet/ip.h>
 #  include <netinet/tcp.h>
 #  include <sys/socket.h>
-#  include <sys/types.h>
 #  include <unistd.h>
 #  ifdef CAF_POLL_MULTIPLEXER
 #    include <poll.h>
