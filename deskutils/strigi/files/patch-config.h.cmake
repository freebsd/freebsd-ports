--- ./config.h.cmake.orig	2009-01-13 00:50:22.000000000 +0300
+++ ./config.h.cmake	2009-03-21 00:02:27.000000000 +0300
@@ -40,7 +40,7 @@
 //thread stuff
 //////////////////////////////
 #cmakedefine CMAKE_USE_WIN32_THREADS_INIT 1
-#cmakedefine CMAKE_HAVE_PTHREAD_CREATE 1
+#cmakedefine CMAKE_HAVE_PTHREAD_H 1
 
 //////////////////////////////
 //types
