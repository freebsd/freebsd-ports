--- src/platform.h.orig	2019-03-15 04:11:43 UTC
+++ src/platform.h
@@ -197,7 +197,7 @@ float perf_count_to_sec(u64 counter);
 
 #if defined(_WIN32)
 #include "platform_windows.h"
-#elif defined(__linux__) || defined(__MACH__)
+#elif defined(__linux__) || defined(__MACH__) || defined(__FreeBSD__)
 #include "platform_unix.h"
 #endif
 
