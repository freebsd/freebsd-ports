--- hphp/runtime/base/program_functions.cpp.orig	2013-07-21 12:37:28.901704505 +0200
+++ hphp/runtime/base/program_functions.cpp	2013-07-21 12:37:50.729630002 +0200
@@ -1290,10 +1290,10 @@
 
 void hphp_process_init() {
   pthread_attr_t attr;
-#ifndef __APPLE__
-  pthread_getattr_np(pthread_self(), &attr);
-#else
+#if defined(__APPLE__) || defined(__FreeBSD__)
   pthread_attr_init(&attr);
+#else
+  pthread_getattr_np(pthread_self(), &attr);
 #endif
   Util::init_stack_limits(&attr);
   pthread_attr_destroy(&attr);
