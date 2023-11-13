--- unix/minizip/ioapi.h	2023-11-12 22:11:21.368667000 -0500
+++ unix/minizip/ioapi.h	2023-11-12 22:12:10.762868000 -0500
@@ -44,7 +44,7 @@
 #include <stdlib.h>
 #include "zlib.h"
 
-#if defined(USE_FILE32API)
+#if defined(USE_FILE32API) || defined (__FreeBSD__)
 #define fopen64 fopen
 #define ftello64 ftell
 #define fseeko64 fseek
