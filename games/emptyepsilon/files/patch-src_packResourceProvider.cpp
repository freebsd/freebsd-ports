--- src/packResourceProvider.cpp.orig	2023-06-14 07:23:22 UTC
+++ src/packResourceProvider.cpp
@@ -7,7 +7,7 @@
 #ifdef _WIN32
 #include <malloc.h>
 #else
-#include <alloca.h>
+#include <stdlib.h>
 #endif
 
 #ifdef ANDROID
