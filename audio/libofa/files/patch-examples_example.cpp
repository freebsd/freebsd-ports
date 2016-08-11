--- examples/example.cpp.orig	2016-07-26 15:10:24 UTC
+++ examples/example.cpp
@@ -7,6 +7,8 @@
 
 -------------------------------------------------------------------*/
 
+#include <stdio.h>
+#include <string.h>
 #include "protocol.h"
 
 AudioData* loadWaveFile(char *file);
