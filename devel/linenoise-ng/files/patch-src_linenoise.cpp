--- src/linenoise.cpp.orig	2017-03-06 16:01:33 UTC
+++ src/linenoise.cpp
@@ -110,6 +110,7 @@
 #include <unistd.h>
 #include <stdlib.h>
 #include <string.h>
+#include <sys/stat.h>
 #include <sys/types.h>
 #include <sys/ioctl.h>
 #include <cctype>
