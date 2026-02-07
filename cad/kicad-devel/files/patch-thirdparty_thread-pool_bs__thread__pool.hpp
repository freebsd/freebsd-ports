--- thirdparty/thread-pool/bs_thread_pool.hpp.orig	2025-09-14 18:08:58 UTC
+++ thirdparty/thread-pool/bs_thread_pool.hpp
@@ -96,7 +96,7 @@ import std;
     #endif
 #endif
 
-#if defined(__linux__)
+#if defined(__linux__) || defined (__FreeBSD__)
     // On Linux, <sys/sysmacros.h> defines macros called `major` and `minor`. We undefine them here so the `version` struct can work.
     #ifdef major
         #undef major
