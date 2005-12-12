--- src/Classes/Abstract/basic.hpp.orig	Sat Dec  3 03:08:07 2005
+++ src/Classes/Abstract/basic.hpp	Mon Dec  5 18:43:02 2005
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
