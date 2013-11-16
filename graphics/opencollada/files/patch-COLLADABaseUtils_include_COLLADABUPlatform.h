--- COLLADABaseUtils/include/COLLADABUPlatform.h.orig	2013-11-16 10:53:05.000000000 +0100
+++ COLLADABaseUtils/include/COLLADABUPlatform.h	2013-11-16 10:53:21.000000000 +0100
@@ -23,7 +23,7 @@
 #  define COLLADABU_OS_WIN64
 #elif (defined(WIN32) || defined(_WIN32) || defined(__WIN32__) || defined(__NT__))
 #  define COLLADABU_OS_WIN32
-#elif defined(__linux__) || defined(__linux)
+#elif defined(__linux__) || defined(__linux) || defined(__FreeBSD__)
 #  define COLLADABU_OS_LINUX
 #endif
 
