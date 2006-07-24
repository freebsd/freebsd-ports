--- examples/wavefile.cpp.orig	Mon Jul 24 11:13:26 2006
+++ examples/wavefile.cpp	Mon Jul 24 11:13:05 2006
@@ -11,6 +11,7 @@
 #include "io.h"
 #endif
 #include <fcntl.h>
+#include <unistd.h>
 
 static bool readBytes(int fd, unsigned char *buf, int size) {
     int ct = 0;
