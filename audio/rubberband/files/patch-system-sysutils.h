--- src/system/sysutils.h-dist	2012-01-08 17:15:39.369149714 +0100
+++ src/system/sysutils.h	2012-01-08 17:19:42.384145925 +0100
@@ -41,7 +41,8 @@
 #include <malloc.h>
 #else
 #ifndef __MSVC__
-#include <alloca.h>
+/* linux stdlib also includes alloca.h */
+#include <stdlib.h>
 #endif
 #endif
 
