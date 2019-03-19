--- src/system_includes.h.orig	2019-03-15 04:11:43 UTC
+++ src/system_includes.h
@@ -48,7 +48,7 @@
 
 #include "gl.h"
 
-#elif defined(__linux__)
+#elif defined(__linux__) || defined(__FreeBSD__)
 
 #include "gl.h"
 
