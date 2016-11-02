--- src/packResourceProvider.cpp.orig	2016-08-31 19:10:48 UTC
+++ src/packResourceProvider.cpp
@@ -5,7 +5,7 @@
 #ifdef __WIN32__
 #include <malloc.h>
 #else
-#include <alloca.h>
+#include <stdlib.h>
 #endif
 
 static inline int readInt(FILE* f)
