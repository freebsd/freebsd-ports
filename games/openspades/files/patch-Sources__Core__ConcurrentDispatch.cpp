--- Sources/Core/ConcurrentDispatch.cpp.orig	2014-06-23 15:55:03.000000000 +0400
+++ Sources/Core/ConcurrentDispatch.cpp	2014-07-30 23:05:09.324201495 +0400
@@ -38,7 +38,7 @@
 #ifndef _MSC_VER
 #include <unistd.h>
 #endif
-#if defined(__GNUC__)
+#if defined(__linux__)
 #include <sys/sysinfo.h>
 #endif
 #endif
@@ -67,7 +67,7 @@
         if(count < 1) { count = 1; }
     }
     return count;
-#elif defined(__GNUC__)
+#elif defined(__linux__)
     return get_nprocs();
 #else
     return sysconf(_SC_NPROCESSORS_ONLN);
