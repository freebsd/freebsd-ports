--- src/random/fastfunc.h.orig	2020-05-15 04:49:19 UTC
+++ src/random/fastfunc.h
@@ -27,7 +27,7 @@
 #include <cmath>
 #include <vector>
 
-#if !defined(__APPLE__)
+#if !defined(__APPLE__) && !defined(__FreeBSD__)
 #include <malloc.h>
 #endif
 
