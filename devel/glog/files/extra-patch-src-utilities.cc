--- src/utilities.cc.orig	2009-01-23 09:37:14.000000000 +0800
+++ src/utilities.cc	2009-02-04 11:25:50.000000000 +0800
@@ -187,8 +187,6 @@
 #ifndef __NR_gettid
 #ifdef OS_MACOSX
 #define __NR_gettid SYS_gettid
-#elif ! defined __i386__
-#error "Must define __NR_gettid for non-x86 platforms"
 #else
 #define __NR_gettid 224
 #endif
@@ -214,7 +212,7 @@
   return GetCurrentThreadId();
 #else
   // If none of the techniques above worked, we use pthread_self().
-  return (pid_t)pthread_self();
+  return reinterpret_cast<unsigned long>(pthread_self());
 #endif
 }
 
