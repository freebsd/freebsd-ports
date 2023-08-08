--- libs/core/zone.cpp.orig	2022-12-31 03:37:53 UTC
+++ libs/core/zone.cpp
@@ -33,6 +33,8 @@
 
 #include "core.h"
 
+#if 0
+
 // MACROS ------------------------------------------------------------------
 
 #define SMALLID				0x22
@@ -515,4 +517,5 @@ void Z_Free(void* ptr)
 	unguard;
 }
 
+#endif
 #endif
