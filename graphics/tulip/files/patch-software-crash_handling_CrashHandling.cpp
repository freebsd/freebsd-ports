--- software/crash_handling/CrashHandling.cpp.orig	2014-04-18 10:33:31.000000000 +0200
+++ software/crash_handling/CrashHandling.cpp	2014-04-18 10:34:25.000000000 +0200
@@ -38,7 +38,7 @@
 /*
   Linux/MacOS-specific handling
  */
-#if defined(__unix__) || defined(__APPLE__)
+#if (defined(__unix__) || defined(__APPLE__)) && !defined(__FreeBSD__)
 
 # if defined(__i386__) || defined(__amd64__)
 
