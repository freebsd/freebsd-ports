--- src/util.cpp.orig	2020-01-25 02:15:35 UTC
+++ src/util.cpp
@@ -41,6 +41,8 @@
 #ifdef ISPC_HOST_IS_LINUX
 #include <alloca.h>
 #include <unistd.h>
+#elif defined(ISPC_HOST_IS_FREEBSD)
+#include <unistd.h>
 #elif defined(ISPC_HOST_IS_WINDOWS)
 #include <malloc.h>
 #include <shlwapi.h>
