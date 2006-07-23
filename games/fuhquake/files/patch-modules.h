--- modules.h.orig	Wed Jan  7 00:43:26 2004
+++ modules.h	Sun Jan 22 22:07:23 2006
@@ -24,7 +24,7 @@
 
 #include "security.h"
 
-#ifdef __linux__
+#if defined(__linux__) || defined(__FreeBSD__)
 #include <dlfcn.h>
 #endif
 
