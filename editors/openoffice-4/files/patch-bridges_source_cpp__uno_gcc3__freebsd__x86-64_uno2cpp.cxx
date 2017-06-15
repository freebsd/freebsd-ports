--- bridges/source/cpp_uno/gcc3_freebsd_x86-64/uno2cpp.cxx.orig	2016-09-10 13:54:56 UTC
+++ bridges/source/cpp_uno/gcc3_freebsd_x86-64/uno2cpp.cxx
@@ -28,6 +28,9 @@
 #include <exception>
 #include <cstddef>
 #include <cxxabi.h>
+#if OSL_DEBUG_LEVEL > 1
+#include <stdio.h>
+#endif
 #include <stdlib.h>
 #include <string.h>
 
