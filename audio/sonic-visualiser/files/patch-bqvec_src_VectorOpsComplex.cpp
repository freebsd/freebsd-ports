--- bqvec/src/VectorOpsComplex.cpp.orig	2020-04-16 18:11:58 UTC
+++ bqvec/src/VectorOpsComplex.cpp
@@ -50,6 +50,8 @@
 #ifndef alloca
 #define alloca _alloca
 #endif
+#elif defined(__FreeBSD__)
+#include <stdlib.h>
 #else
 #include <alloca.h>
 #endif
