--- src/libprojectM/Renderer/hlslparser/src/HLSLParser.cpp.orig	2018-12-03 11:23:19 UTC
+++ src/libprojectM/Renderer/hlslparser/src/HLSLParser.cpp
@@ -20,6 +20,9 @@
 #include <iostream>
 #include <cmath>
 #include <cstdlib>
+#ifdef __FreeBSD__
+#include <sys/types.h>
+#endif
 
 namespace M4
 {
