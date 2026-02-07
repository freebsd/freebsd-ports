--- thirdparty/headeronly/cfgpath.h.orig	2019-08-18 10:23:32 UTC
+++ thirdparty/headeronly/cfgpath.h
@@ -39,7 +39,7 @@
 #define mkdir _mkdir
 #endif
 
-#if defined(__linux__) || defined(__APPLE__)
+#if defined(__linux__) || defined(__APPLE__) || defined(__FreeBSD__)
 #include <string.h>
 #include <stdlib.h>
 #include <sys/stat.h>
