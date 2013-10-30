--- src/Constante.cpp.orig	2013-10-29 17:15:21.000000000 +0100
+++ src/Constante.cpp	2013-10-29 17:18:30.000000000 +0100
@@ -32,6 +32,7 @@
 #define WIN32_LEAN_AND_MEAN
 #include <windows.h>
 #else
+#include <cstdlib>
 #include <unistd.h>
 #endif
 
