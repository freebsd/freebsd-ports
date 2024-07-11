--- source/loader/ze_loader.cpp.orig	2024-07-01 19:14:47 UTC
+++ source/loader/ze_loader.cpp
@@ -10,11 +10,11 @@
 #include "driver_discovery.h"
 #include <iostream>
 
-#ifdef __linux__
+#if defined(__FreeBSD__) || defined(__linux__)
 #include <unistd.h>
 #include <sys/types.h>
 #include <pwd.h>
-#endif // __linux__
+#endif // defined(__FreeBSD__) || defined(__linux__)
 
 namespace loader
 {
