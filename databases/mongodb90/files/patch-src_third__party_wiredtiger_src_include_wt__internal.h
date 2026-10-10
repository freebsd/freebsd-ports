--- src/third_party/wiredtiger/src/include/wt_internal.h.orig
+++ src/third_party/wiredtiger/src/include/wt_internal.h
@@ -600,13 +600,13 @@
 #ifdef _WIN32
 #include "os_windows.h"
 #else
 #include "posix.h"
 #endif
 
-#ifdef __linux__
+#if defined(__linux__) || defined(__FreeBSD__)
 #include "os_linux.h"
 #elif __APPLE__
 #include "os_darwin.h"
 #endif
 
 #include "misc.h"
@@ -660,13 +660,13 @@
 #include "connection.h"
 
 #include "extern.h"
 #ifdef _WIN32
 #include "extern_win.h"
 #else
 #include "extern_posix.h"
-#ifdef __linux__
+#if defined(__linux__) || defined(__FreeBSD__)
 #include "extern_linux.h"
 #elif __APPLE__
 #include "extern_darwin.h"
 #endif
 #endif
 #include "verify_build.h"
