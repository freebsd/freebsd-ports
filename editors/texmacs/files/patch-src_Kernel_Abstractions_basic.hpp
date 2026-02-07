--- src/Kernel/Abstractions/basic.hpp.orig	2015-12-03 08:18:07 UTC
+++ src/Kernel/Abstractions/basic.hpp
@@ -15,9 +15,10 @@
 #include <math.h>
 
 #ifdef HAVE_INTPTR_T
-#ifdef OS_SUN
+#ifdef HAVE_INTTYPES_H
 #include <inttypes.h>
-#else
+#endif
+#ifdef HAVE_STDINT_H
 #include <stdint.h>
 #endif
 #else
