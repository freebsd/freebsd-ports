--- modules.h.orig	Wed Feb  4 21:13:04 2004
+++ modules.h	Wed Feb  4 21:13:36 2004
@@ -24,7 +24,7 @@
 
 #include "security.h"
 
-#ifdef __linux__
+#if defined(__linux__) || defined(__FreeBSD__)
 #include <dlfcn.h>
 #endif
 
