--- source/matplot/util/popen.cpp.orig	2025-11-25 15:11:25 UTC
+++ source/matplot/util/popen.cpp
@@ -121,7 +121,7 @@ int common_pipe::close(int *exit_code)
 }
 #endif // _WIN32 implementtion
 
-#if defined(__linux) || defined(__APPLE__)
+#if defined(__linux) || defined(__APPLE__) || defined(__FreeBSD__)
 
 #include <cerrno>
 #include <sys/wait.h> // waitpid
