FreeBSD does not know either 
* PTHREAD_RECURSIVE_MUTEX_INITIALIZER nor 
* PTHREAD_RECUSRIVE_MUTEX_INITIALIZER_NP


--- src/actions.cpp.orig        2017-03-08 20:42:28 UTC
+++ src/actions.cpp
@@ -2048,6 +2048,8 @@ namespace {
  #if defined(__APPLE__)
   /* This is the critical section object (statically allocated). */
   static pthread_mutex_t cs =  PTHREAD_RECURSIVE_MUTEX_INITIALIZER;
+ #elif defined(__FreeBSD__)
+  static pthread_mutex_t cs =  PTHREAD_MUTEX_INITIALIZER;
  #else
   static pthread_mutex_t cs =  PTHREAD_RECURSIVE_MUTEX_INITIALIZER_NP;
  #endif
