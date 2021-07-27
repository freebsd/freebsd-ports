--- source/posixthr.h.orig	2021-07-27 18:45:53 UTC
+++ source/posixthr.h
@@ -22,7 +22,7 @@
 #define _POSIXTHR_H
 
 
-#ifdef __linux__
+#if defined(__linux__) || defined(__FreeBSD__)
 
 #include <stdlib.h>
 #include <pthread.h>
