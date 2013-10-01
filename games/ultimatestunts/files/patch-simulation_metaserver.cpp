--- simulation/metaserver.cpp.orig	2012-08-25 10:07:01.000000000 +0000
+++ simulation/metaserver.cpp
@@ -16,6 +16,7 @@
  ***************************************************************************/
 #include <cstdio>
 #include <cstdlib>
+#include <unistd.h>
 #include <sys/types.h>
 #include <sys/socket.h>
 #include <netinet/in.h>
