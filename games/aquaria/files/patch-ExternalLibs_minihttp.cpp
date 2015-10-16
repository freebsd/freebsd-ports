https://github.com/AquariaOSE/Aquaria/pull/21

--- ExternalLibs/minihttp.cpp.orig	2015-08-16 13:19:19 UTC
+++ ExternalLibs/minihttp.cpp
@@ -32,6 +32,7 @@
 #  include <sys/types.h>
 #  include <unistd.h>
 #  include <fcntl.h>
+#  include <netinet/in.h>
 #  include <sys/socket.h>
 #  include <netdb.h>
 #  define SOCKET_ERROR (-1)
