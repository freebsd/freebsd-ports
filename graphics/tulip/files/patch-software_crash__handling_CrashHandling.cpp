--- software/crash_handling/CrashHandling.cpp.orig	2015-04-18 20:15:52 UTC
+++ software/crash_handling/CrashHandling.cpp
@@ -48,7 +48,7 @@ void setExtraSymbolsSearchPaths(const st
 /*
   Linux/MacOS-specific handling
  */
-#if defined(__unix__) || defined(__APPLE__)
+#if (defined(__unix__) || defined(__APPLE__)) && !defined(__FreeBSD__)
 
 # if defined(__i386__) || defined(__amd64__)
 
