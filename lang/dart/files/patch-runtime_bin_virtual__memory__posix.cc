Skip the Linux-only prctl(PR_SET_VMA) mapping names on FreeBSD
(series 0009).
FreeBSD-specific, not submitted upstream yet.
--- runtime/bin/virtual_memory_posix.cc.orig	2026-09-29 08:00:52 UTC
+++ runtime/bin/virtual_memory_posix.cc
@@ -12,7 +12,8 @@
 #include <sys/mman.h>
 #include <unistd.h>
 
-#if defined(DART_HOST_OS_ANDROID) || defined(DART_HOST_OS_LINUX)
+#if (defined(DART_HOST_OS_ANDROID) || defined(DART_HOST_OS_LINUX)) && \
+    !defined(__FreeBSD__)
 #include <sys/prctl.h>
 #endif
 
@@ -72,7 +73,8 @@ VirtualMemory* VirtualMemory::Allocate(intptr_t size,
     return nullptr;
   }
 
-#if defined(DART_HOST_OS_ANDROID) || defined(DART_HOST_OS_LINUX)
+#if (defined(DART_HOST_OS_ANDROID) || defined(DART_HOST_OS_LINUX)) && \
+    !defined(__FreeBSD__)
   // PR_SET_VMA was only added to mainline Linux in 5.17, and some versions of
   // the Android NDK have incorrect headers, so we manually define it if absent.
 #if !defined(PR_SET_VMA)
