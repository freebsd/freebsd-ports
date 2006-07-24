--- examples/uselame.cpp.orig	Mon Jul 24 11:11:58 2006
+++ examples/uselame.cpp	Mon Jul 24 11:12:09 2006
@@ -13,6 +13,8 @@
 #include <sys/wait.h>
 #endif
 
+#include <unistd.h>
+
 AudioData *loadWaveFile(char *file);
 
 //	loadDataUsingLAME
