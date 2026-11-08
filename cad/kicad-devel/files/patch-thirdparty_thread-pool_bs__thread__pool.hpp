--- thirdparty/thread-pool/bs_thread_pool.hpp.orig	2026-08-21 21:35:49 UTC
+++ thirdparty/thread-pool/bs_thread_pool.hpp
@@ -82,7 +82,7 @@ import std;
         #include <windows.h>
         #undef min
         #undef max
-    #elif defined(__linux__) || defined(__APPLE__)
+    #elif defined(__linux__) || defined(__APPLE__) || defined (__FreeBSD__)
         #include <pthread.h>
         #include <sched.h>
         #include <sys/resource.h>
@@ -96,7 +96,7 @@ import std;
     #endif
 #endif
 
-#if defined(__linux__)
+#if defined(__linux__) || defined (__FreeBSD__)
     // On Linux, <sys/sysmacros.h> defines macros called `major` and `minor`. We undefine them here so the `version` struct can work.
     #ifdef major
         #undef major
@@ -663,7 +663,7 @@ inline bool set_os_process_affinity(const std::vector<
     for (std::size_t i = 0; i < std::min<std::size_t>(affinity.size(), sizeof(DWORD_PTR) * 8); ++i)
         process_mask |= (affinity[i] ? (1ULL << i) : 0ULL);
     return SetProcessAffinityMask(GetCurrentProcess(), process_mask) != 0;
-    #elif defined(__linux__)
+    #elif defined(__linux__) || defined (__FreeBSD__)
     cpu_set_t cpu_set;
     CPU_ZERO(&cpu_set);
     for (std::size_t i = 0; i < std::min<std::size_t>(affinity.size(), CPU_SETSIZE); ++i)
@@ -865,7 +865,7 @@ class [[nodiscard]] this_thread (public)
         if (result == 0)
             return std::nullopt;
         return name;
-    #elif defined(__linux__) || defined(__APPLE__)
+    #elif defined(__linux__) || defined(__APPLE__) || defined (__FreeBSD__)
         #ifdef __linux__
         // On Linux thread names are limited to 16 characters, including the null terminator.
         constexpr std::size_t buffer_size = 16;
