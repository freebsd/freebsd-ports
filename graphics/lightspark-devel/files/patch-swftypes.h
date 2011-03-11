--- swftypes.h.orig	2011-03-07 07:10:16.000000000 +0300
+++ swftypes.h	2011-03-09 01:19:26.000000000 +0300
@@ -40,7 +40,7 @@
  // TODO: Proper CMake check
  #include <arpa/inet.h>
 #endif
-#include <endian.h>
+#include <sys/endian.h>
 
 #ifdef BIG_ENDIAN
 #include <algorithm>
