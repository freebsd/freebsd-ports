--- libs/hawknl/src/nlinternal.h.orig	2008-08-31 03:59:14.000000000 +0400
+++ libs/hawknl/src/nlinternal.h	2008-10-13 00:15:18.000000000 +0400
@@ -28,7 +28,7 @@
 /* for malloc and free */
 #include <stdlib.h>
 #ifndef MACOSX
-#include <malloc.h>
+#include <stdlib.h>
 #endif
 
 /* Windows CE does not have time.h functions */
