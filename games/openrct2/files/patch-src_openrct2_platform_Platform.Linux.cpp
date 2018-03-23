--- src/openrct2/platform/Platform.Linux.cpp.orig	2018-03-18 20:26:14 UTC
+++ src/openrct2/platform/Platform.Linux.cpp
@@ -16,6 +16,11 @@
 
 #if defined(__FreeBSD__) || defined(__OpenBSD__) || (defined(__linux__) && !defined(__ANDROID__))
 
+#ifdef __FreeBSD__
+#include <stddef.h>
+#include <sys/types.h>
+#include <sys/sysctl.h>
+#endif
 #include <limits.h>
 #include <pwd.h>
 #include "../core/Path.hpp"
