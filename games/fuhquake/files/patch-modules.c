--- modules.c.orig	Wed Feb  4 21:05:56 2004
+++ modules.c	Wed Feb  4 21:14:23 2004
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
