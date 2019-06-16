--- folly/Subprocess.h.orig	2019-06-16 07:46:12 UTC
+++ folly/Subprocess.h
@@ -95,7 +95,7 @@
 #include <signal.h>
 #include <sys/types.h>
 
-#if __APPLE__
+#if defined(__APPLE__) || defined(__FreeBSD__)
 #include <sys/wait.h>
 #else
 #include <wait.h>
