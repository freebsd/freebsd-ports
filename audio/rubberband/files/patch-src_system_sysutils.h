--- src/system/sysutils.h.orig	2012-10-28 10:30:09 UTC
+++ src/system/sysutils.h
@@ -41,7 +41,8 @@
 #include <malloc.h>
 #else
 #ifndef __MSVC__
-#include <alloca.h>
+/* linux stdlib also includes alloca.h */
+#include <stdlib.h>
 #endif
 #endif
 
