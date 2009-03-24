--- ./src/streams/strigi/strigi_thread.h.orig	2009-01-13 00:50:17.000000000 +0300
+++ ./src/streams/strigi/strigi_thread.h	2009-03-21 00:01:51.000000000 +0300
@@ -23,7 +23,7 @@
 
 #include <config.h>
 
-#if defined(CMAKE_HAVE_PTHREAD_CREATE)
+#if defined(CMAKE_HAVE_PTHREAD_H)
     #include <pthread.h>
     #define STRIGI_MUTEX_DEFINE(x) pthread_mutex_t x
     #define STRIGI_MUTEX_INIT(x) pthread_mutex_init(x, 0)
