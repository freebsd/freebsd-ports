--- source/matplot/util/popen.h.orig	2025-11-25 15:02:56 UTC
+++ source/matplot/util/popen.h
@@ -23,7 +23,7 @@ class proc_pipe  (protected)
     FILE *file_ = nullptr; ///< C file handle for I/O (not both)
 };
 
-#elif defined(__linux) || defined(__APPLE__)
+#elif defined(__linux) || defined(__APPLE__) || defined(__FreeBSD__)
 
 #include <unistd.h> // pid_t
 
