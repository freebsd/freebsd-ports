--- src/1base/abi.h.orig	2015-01-13 21:23:05.548499482 +0800
+++ src/1base/abi.h	2015-01-13 21:23:29.098504301 +0800
@@ -31,7 +31,7 @@
 #endif
 
 #include <string>
-
+#include <stdlib.h>
 // Always verify that a file of level N does not include headers > N!
 
 #ifndef HAM_ROOT_H
