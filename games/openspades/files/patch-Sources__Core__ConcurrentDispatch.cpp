--- Sources/Core/ConcurrentDispatch.cpp.orig	2014-06-23 11:55:03 UTC
+++ Sources/Core/ConcurrentDispatch.cpp
@@ -38,7 +38,7 @@
 #ifndef _MSC_VER
 #include <unistd.h>
 #endif
-#if defined(__GNUC__)
+#if defined(__linux__)
 #include <sys/sysinfo.h>
 #endif
 #endif
@@ -67,7 +67,7 @@ static int GetNumCores() {
         if(count < 1) { count = 1; }
     }
     return count;
-#elif defined(__GNUC__)
+#elif defined(__linux__)
     return get_nprocs();
 #else
     return sysconf(_SC_NPROCESSORS_ONLN);
