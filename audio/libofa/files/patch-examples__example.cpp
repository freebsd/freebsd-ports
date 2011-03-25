--- ./examples/example.cpp.orig	2011-03-18 11:01:22.000000000 -0400
+++ ./examples/example.cpp	2011-03-18 11:01:22.000000000 -0400
@@ -7,6 +7,8 @@
 
 -------------------------------------------------------------------*/
 
+#include <stdio.h>
+#include <string.h>
 #include "protocol.h"
 
 AudioData* loadWaveFile(char *file);
