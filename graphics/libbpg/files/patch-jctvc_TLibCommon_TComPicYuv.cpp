--- jctvc/TLibCommon/TComPicYuv.cpp.orig	2015-01-11 16:17:07 UTC
+++ jctvc/TLibCommon/TComPicYuv.cpp
@@ -41,7 +41,7 @@
 
 #ifdef __APPLE__
 #include <malloc/malloc.h>
-#else
+#elif __Linux__
 #include <malloc.h>
 #endif
 
