--- samples/cpp/benchmark_app/main.cpp.orig	2026-04-10 09:44:43 UTC
+++ samples/cpp/benchmark_app/main.cpp
@@ -41,7 +41,7 @@
 #include <psapi.h>
 #elif defined(__APPLE__)
 #include <sys/resource.h>
-#elif defined(__linux__)
+#elif defined(__linux__) || defined(__FreeBSD__)
 #include <fstream>
 #include <regex>
 #include <sstream>
