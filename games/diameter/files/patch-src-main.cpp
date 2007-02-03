--- src/main.cpp.orig	Mon Jan 29 18:36:35 2007
+++ src/main.cpp	Wed Jan 31 16:36:40 2007
@@ -9,7 +9,6 @@
 #ifdef _POSIX_C_SOURCE	// shut up pyconfig.h complaints
 #undef _POSIX_C_SOURCE
 #endif
-#include <Python.h>
 
 #ifdef __unix__
 #else
@@ -41,6 +40,7 @@
 #include "./res/loadworld.h"
 #include "./wor/pylevel.h"
 
+#include <Python.h>
 
 TextureList TTemp;
 UTextureList TextureDelet;
