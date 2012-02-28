--- software/crash_handling/StackWalker.cpp.orig	2012-02-24 15:18:04.000000000 +0100
+++ software/crash_handling/StackWalker.cpp	2012-02-24 15:23:54.000000000 +0100
@@ -29,10 +29,10 @@
   printCallStack(std::cerr, maxDepth);
 }
 
-#if defined(__linux) || defined(__APPLE__)
+#if defined(__linux) || defined(__APPLE__) || defined(__FreeBSD__)
 
 #include <cxxabi.h>
-#ifndef __APPLE__
+#if !defined(__APPLE__) && !defined(__FreeBSD__)
 #include <execinfo.h>
 #else
 #include <dlfcn.h>
