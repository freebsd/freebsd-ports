--- src/packResourceProvider.cpp.orig	2021-06-23 12:12:02 UTC
+++ src/packResourceProvider.cpp
@@ -5,7 +5,7 @@
 #ifdef _WIN32
 #include <malloc.h>
 #else
-#include <alloca.h>
+#include <stdlib.h>
 #endif
 
 #ifdef _MSC_VER
