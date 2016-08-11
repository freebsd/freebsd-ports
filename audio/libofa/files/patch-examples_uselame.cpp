--- examples/uselame.cpp.orig	2016-07-26 15:10:24 UTC
+++ examples/uselame.cpp
@@ -12,6 +12,7 @@
 #else
 #include <sys/wait.h>
 #endif
+#include <unistd.h>
 
 AudioData *loadWaveFile(char *file);
 
