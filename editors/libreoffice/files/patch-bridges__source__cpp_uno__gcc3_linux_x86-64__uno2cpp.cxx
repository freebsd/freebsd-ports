--- ./bridges/source/cpp_uno/gcc3_linux_x86-64/uno2cpp.cxx.orig	2012-07-03 07:01:28.000000000 -0400
+++ ./bridges/source/cpp_uno/gcc3_linux_x86-64/uno2cpp.cxx	2012-07-17 13:02:19.000000000 -0400
@@ -26,7 +26,11 @@
  *
  ************************************************************************/
 
+#if defined (FREEBSD) || defined(NETBSD) || defined(OPENBSD) || defined(DRAGONFLY)
+#include <stdlib.h>
+#else
 #include <alloca.h>
+#endif
 #include <exception>
 #include <typeinfo>
 
