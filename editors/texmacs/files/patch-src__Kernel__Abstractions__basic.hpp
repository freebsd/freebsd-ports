--- src/Kernel/Abstractions/basic.hpp.orig	2008-05-01 17:24:56.000000000 +0800
+++ src/Kernel/Abstractions/basic.hpp	2008-05-01 17:25:51.000000000 +0800
@@ -24,9 +24,10 @@
 // instead of include <iostream.h>
 
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
