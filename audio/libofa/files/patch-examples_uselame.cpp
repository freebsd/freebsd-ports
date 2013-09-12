--- examples/uselame.cpp.orig	2013-09-12 09:10:31.000000000 +0000
+++ examples/uselame.cpp	2013-09-12 09:10:42.000000000 +0000
@@ -12,6 +12,7 @@
 #else
 #include <sys/wait.h>
 #endif
+#include <unistd.h>
 
 AudioData *loadWaveFile(char *file);
 
