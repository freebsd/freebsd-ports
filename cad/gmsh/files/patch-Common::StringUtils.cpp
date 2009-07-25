--- Common/StringUtils.cpp-xxx	2009-07-20 16:49:34.000000000 -0500
+++ Common/StringUtils.cpp	2009-07-20 16:49:53.000000000 -0500
@@ -9,6 +9,7 @@
 
 #include "StringUtils.h"
 #include "GmshMessage.h"
+#include <cstdio>
 
 void SwapBytes(char *array, int size, int n)
 {
