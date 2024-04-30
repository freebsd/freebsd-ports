--- libshiboken/signature/signature_globals.cpp.orig	2024-04-29 02:02:21 UTC
+++ libshiboken/signature/signature_globals.cpp
@@ -210,7 +210,7 @@ static int init_phase_2(safe_globals_struc *p, PyMetho
 ////////////////////////////////////////////////////////////////////////////
 // a stack trace for linux-like platforms
 #include <cstdio>
-#if defined(__GLIBC__)
+#if defined(__GLIBC__) || defined(__FreeBSD__)
 #  include <execinfo.h>
 #endif
 #include <signal.h>
@@ -218,7 +218,7 @@ static void handler(int sig) {
 #include <unistd.h>
 
 static void handler(int sig) {
-#if defined(__GLIBC__)
+#if defined(__GLIBC__) || defined(__FreeBSD__)
     void *array[30];
     size_t size;
 
@@ -228,7 +228,7 @@ static void handler(int sig) {
     // print out all the frames to stderr
 #endif
     std::fprintf(stderr, "Error: signal %d:\n", sig);
-#if defined(__GLIBC__)
+#if defined(__GLIBC__) || defined(__FreeBSD__)
     backtrace_symbols_fd(array, size, STDERR_FILENO);
 #endif
     exit(1);
