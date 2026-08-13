--- ext/linenoise-ng/src/linenoise.cpp.orig	2026-01-26 17:14:23 UTC
+++ ext/linenoise-ng/src/linenoise.cpp
@@ -109,6 +109,7 @@
 #include <stdlib.h>
 #include <string.h>
 #include <sys/ioctl.h>
+#include <sys/stat.h>
 #include <sys/types.h>
 #include <termios.h>
 #include <unistd.h>
