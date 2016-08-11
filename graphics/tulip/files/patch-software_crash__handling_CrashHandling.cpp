--- software/crash_handling/CrashHandling.cpp.orig	2016-07-07 20:15:39 UTC
+++ software/crash_handling/CrashHandling.cpp
@@ -78,7 +78,7 @@ static void dumpStackTrace(StackWalker &
 /*
   Linux/MacOS-specific handling
  */
-#if defined(__unix__) || defined(__APPLE__)
+#if (defined(__unix__) || defined(__APPLE__)) && !defined(__FreeBSD__)
 
 #if defined(__i386__) || defined(__amd64__)
 
