--- src/system/sysutils.h-dist	2012-01-08 17:15:39.369149714 +0100
+++ src/system/sysutils.h	2012-01-08 17:19:42.384145925 +0100
@@ -27,7 +27,8 @@
 #ifdef __MINGW32__
 #include <malloc.h>
 #else
-#include <alloca.h>
+/* linux stdlib also includes alloca.h */
+#include <stdlib.h>
 #endif
 
 
