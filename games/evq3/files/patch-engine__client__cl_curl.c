--- ./engine/client/cl_curl.c.orig	Sat Mar 31 20:25:28 2007
+++ ./engine/client/cl_curl.c	Mon Apr 16 23:56:57 2007
@@ -41,7 +41,7 @@
 #define SYMLOAD(x,y) GetProcAddress(x,y)
 #define OBJFREE(x) FreeLibrary(x)
 
-#elif defined __linux__ || defined __FreeBSD__ || defined MACOS_X || defined __sun
+#elif defined __unix__ || defined MACOS_X || defined __sun
 #include <dlfcn.h>
 #define OBJTYPE void *
 #define OBJLOAD(x) dlopen(x, RTLD_LAZY | RTLD_GLOBAL)
@@ -52,7 +52,7 @@
 #error "Your platform has no lib loading code or it is disabled"
 #endif
 
-#if defined __linux__ || defined __FreeBSD__ || defined MACOS_X
+#if defined __unix__ || defined MACOS_X
 #include <unistd.h>
 #include <sys/types.h>
 #endif
