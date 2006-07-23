--- modules.c.orig	Wed Jan  7 03:51:30 2004
+++ modules.c	Sun Jan 22 22:07:23 2006
@@ -31,10 +31,6 @@
 char _temp_modulename[MAX_OSPATH];
 static registeredModule_t registeredModules[qlib_nummodules];
 
-#ifdef __linux
-#include <dlfcn.h>
-#endif
-
 #ifdef _WIN32
 #define SECURITY_GETFUNC(f) (Security_##f = (Security_##f##_t) GetProcAddress(hSecurity, "Security_" #f))
 #else
