--- examples/wavefile.cpp.orig	2016-07-26 15:10:24 UTC
+++ examples/wavefile.cpp
@@ -11,6 +11,8 @@
 #include "io.h"
 #endif
 #include <fcntl.h>
+#include <sys/types.h>
+#include <unistd.h>
 
 static bool readBytes(int fd, unsigned char *buf, int size) {
     int ct = 0;
