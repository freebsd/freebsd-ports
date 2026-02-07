--- ./simulation/metaserver.cpp.orig	2012-08-25 12:07:01.000000000 +0200
+++ ./simulation/metaserver.cpp	2014-03-15 13:54:11.868249585 +0100
@@ -16,6 +16,7 @@
  ***************************************************************************/
 #include <cstdio>
 #include <cstdlib>
+#include <unistd.h>
 #include <sys/types.h>
 #include <sys/socket.h>
 #include <netinet/in.h>
