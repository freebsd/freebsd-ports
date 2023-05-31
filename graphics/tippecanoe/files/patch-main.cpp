--- main.cpp.orig	2022-09-27 16:15:54 UTC
+++ main.cpp
@@ -34,7 +34,7 @@
 #include <map>
 #include <cmath>
 
-#ifdef __APPLE__
+#if defined(__APPLE__) || defined(__FreeBSD__)
 #include <sys/types.h>
 #include <sys/sysctl.h>
 #include <sys/param.h>
