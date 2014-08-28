# $FreeBSD$
--- src/source/unixtls.cpp.orig	2014-08-21 06:10:50.000000000 +0200
+++ source/unixtls.cpp	2014-08-21 06:12:43.000000000 +0200
@@ -315,7 +315,7 @@
 			       const pthread_attr_t *attr,
 			       void * (*start_routine) (void *),
 			       void * arg)
-#if !defined(__SUNPRO_CC) && !defined(__APPLE__)
+#if !defined(__SUNPRO_CC) && !defined(__APPLE__) && !defined(__FreeBSD__)
   throw ()
 #endif
 {
