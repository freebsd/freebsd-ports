--- software/crash_handling/StackWalker.h.orig	2012-02-24 15:16:55.000000000 +0100
+++ software/crash_handling/StackWalker.h	2012-02-24 15:17:07.000000000 +0100
@@ -83,7 +83,7 @@
 
 };
 
-#if defined(__linux) || defined(__APPLE__)
+#if defined(__linux) || defined(__APPLE__) || defined(__FreeBSD__)
 
 #include <map>
 
