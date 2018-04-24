--- lib/Basics/ArangoGlobalContext.cpp.orig	2018-04-12 13:04:01 UTC
+++ lib/Basics/ArangoGlobalContext.cpp
@@ -145,10 +145,9 @@ ArangoGlobalContext::ArangoGlobalContext
 #ifndef __GLIBC__
   // Increase default stack size for libmusl:
   pthread_attr_t a;
-  memset(&a, 0, sizeof(pthread_attr_t));
+  pthread_attr_init(&a);
   pthread_attr_setstacksize(&a, 8*1024*1024);  // 8MB as in glibc
   pthread_attr_setguardsize(&a, 4096);         // one page
-  pthread_setattr_default_np(&a);
 #endif
 #endif
 #endif
