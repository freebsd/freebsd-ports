--- examples/example.cpp.orig	Mon Jul 24 11:09:39 2006
+++ examples/example.cpp	Mon Jul 24 11:09:50 2006
@@ -7,6 +7,8 @@
 
 -------------------------------------------------------------------*/
 
+#include <stdio.h>
+
 #include "protocol.h"
 
 AudioData* loadWaveFile(char *file);
