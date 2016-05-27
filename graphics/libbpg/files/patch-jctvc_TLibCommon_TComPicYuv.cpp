--- jctvc/TLibCommon/TComPicYuv.cpp.orig	2016-05-15 09:06:19 UTC
+++ jctvc/TLibCommon/TComPicYuv.cpp
@@ -41,7 +41,7 @@
 
 #ifdef __APPLE__
 #include <malloc/malloc.h>
-#else
+#elif __Linux__
 #include <malloc.h>
 #endif
 
