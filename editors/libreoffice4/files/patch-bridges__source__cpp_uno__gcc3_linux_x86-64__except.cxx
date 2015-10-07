--- bridges/source/cpp_uno/gcc3_linux_x86-64/except.cxx.orig	2014-04-22 18:25:28.000000000 -0400
+++ bridges/source/cpp_uno/gcc3_linux_x86-64/except.cxx	2014-05-06 16:19:44.000000000 -0400
@@ -21,6 +21,9 @@
 #include <stdio.h>
 #include <string.h>
 #include <dlfcn.h>
+#if defined(FREEBSD)
+#include <sys/param.h>
+#endif
 
 #include <cxxabi.h>
 #ifndef _GLIBCXX_CDTOR_CALLABI // new in GCC 4.7 cxxabi.h
