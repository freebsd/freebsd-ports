--- modules.c.orig	Wed May 21 17:18:36 2003
+++ modules.c	Wed May 21 17:22:37 2003
@@ -22,7 +22,7 @@
 #include "modules.h"
 #include "version.h"
 
-#ifdef __linux
+#if defined(__linux__) || defined(__FreeBSD__)
 #include <dlfcn.h>
 #endif
 
