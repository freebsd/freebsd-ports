--- base/stl_decl.h.orig	2011-09-29 08:11:48.000000000 +0800
+++ base/stl_decl.h	2011-10-04 21:10:17.695777868 +0800
@@ -25,7 +25,7 @@
 #elif defined(__APPLE__) /* gcc with a twist */
 #include "base/stl_decl_osx.h"
 
-#elif defined(__linux__)
+#elif defined(__linux__) || defined(__FreeBSD__)
 #include "base/stl_decl_linux.h"
 
 #else
