--- examples/wavefile.cpp.orig	2013-09-12 08:58:25.000000000 +0000
+++ examples/wavefile.cpp	2013-09-12 08:58:31.000000000 +0000
@@ -11,6 +11,8 @@
 #include "io.h"
 #endif
 #include <fcntl.h>
+#include <sys/types.h>
+#include <unistd.h>
 
 static bool readBytes(int fd, unsigned char *buf, int size) {
     int ct = 0;
