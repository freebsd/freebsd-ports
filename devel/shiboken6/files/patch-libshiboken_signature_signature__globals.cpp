--- libshiboken/signature/signature_globals.cpp.orig	2024-12-17 09:51:38 UTC
+++ libshiboken/signature/signature_globals.cpp
@@ -208,7 +208,7 @@ static int init_phase_2(safe_globals_struc *p, PyMetho
 ////////////////////////////////////////////////////////////////////////////
 // a stack trace for linux-like platforms
 #include <cstdio>
-#if defined(__GLIBC__)
+#if defined(__GLIBC__) || defined(__FreeBSD__)
 #  include <execinfo.h>
 #endif
 #include <signal.h>
@@ -216,7 +216,7 @@ static void handler(int sig) {
 #include <unistd.h>
 
 static void handler(int sig) {
-#if defined(__GLIBC__)
+#if defined(__GLIBC__) || defined(__FreeBSD__)
     void *array[30];
     // get void *'s for all entries on the stack
     const int size = backtrace(array, 30);
@@ -224,7 +224,7 @@ static void handler(int sig) {
     // print out all the frames to stderr
 #endif
     std::fprintf(stderr, "Error: signal %d:\n", sig);
-#if defined(__GLIBC__)
+#if defined(__GLIBC__) || defined(__FreeBSD__)
     backtrace_symbols_fd(array, size, STDERR_FILENO);
 #endif
     exit(1);
