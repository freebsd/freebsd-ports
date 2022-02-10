--- libs/fst/fstapi.cc.orig	2022-02-10 19:07:14 UTC
+++ libs/fst/fstapi.cc
@@ -62,7 +62,11 @@
 #endif
 
 #ifdef HAVE_ALLOCA_H
+#if defined(__FreeBSD__)
+#include <stdlib.h>
+#else
 #include <alloca.h>
+#endif
 #elif defined(__GNUC__)
 #ifndef __MINGW32__
 #ifndef alloca
