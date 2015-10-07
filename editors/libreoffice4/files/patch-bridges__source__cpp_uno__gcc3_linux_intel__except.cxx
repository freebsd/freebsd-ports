--- bridges/source/cpp_uno/gcc3_linux_intel/except.cxx.orig	2014-04-22 18:25:28.000000000 -0400
+++ bridges/source/cpp_uno/gcc3_linux_intel/except.cxx	2014-05-06 16:19:42.000000000 -0400
@@ -20,6 +20,10 @@
 #include <cstdio>
 #include <cstring>
 #include <dlfcn.h>
+#if defined(FREEBSD)
+#include <sys/param.h>
+#endif
+
 #include <boost/unordered_map.hpp>
 
 #include <cxxabi.h>
