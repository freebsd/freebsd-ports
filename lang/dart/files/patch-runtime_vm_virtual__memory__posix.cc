Skip the Linux-only prctl(PR_SET_VMA) mapping names, and treat the
removed MAP_NORESERVE as 0 on FreeBSD, whose mappings never reserve
swap up front (series 0009).
FreeBSD-specific, not submitted upstream yet.
--- runtime/vm/virtual_memory_posix.cc.orig	2026-09-29 08:00:52 UTC
+++ runtime/vm/virtual_memory_posix.cc
@@ -15,10 +15,16 @@
 #include <sys/syscall.h>
 #include <unistd.h>
 
-#if defined(DART_HOST_OS_ANDROID) || defined(DART_HOST_OS_LINUX)
+#if (defined(DART_HOST_OS_ANDROID) || defined(DART_HOST_OS_LINUX)) && \
+    !defined(__FreeBSD__)
 #include <sys/prctl.h>
 #endif
 
+// FreeBSD removed MAP_NORESERVE; reservations do not commit swap there.
+#if !defined(MAP_NORESERVE)
+#define MAP_NORESERVE 0
+#endif
+
 #if defined(DART_HOST_OS_MACOS)
 #include <mach/mach_init.h>
 #include <mach/vm_map.h>
@@ -679,7 +685,8 @@ VirtualMemory* VirtualMemory::AllocateAligned(intptr_t
   }
 #endif  // defined(DART_ENABLE_RX_WORKAROUNDS)
 
-#if defined(DART_HOST_OS_ANDROID) || defined(DART_HOST_OS_LINUX)
+#if (defined(DART_HOST_OS_ANDROID) || defined(DART_HOST_OS_LINUX)) && \
+    !defined(__FreeBSD__)
   // PR_SET_VMA was only added to mainline Linux in 5.17, and some versions of
   // the Android NDK have incorrect headers, so we manually define it if absent.
 #if !defined(PR_SET_VMA)
