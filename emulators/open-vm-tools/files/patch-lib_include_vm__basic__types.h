--- lib/include/vm_basic_types.h.orig	2017-02-24 22:15:37 UTC
+++ lib/include/vm_basic_types.h
@@ -415,6 +415,7 @@ typedef int64 VmTimeVirtualClock;  /* Vi
       #endif
    #elif defined(__linux__) || \
         (defined(__FreeBSD__) && (__FreeBSD__ + 0))\
+      || (defined(__clang__)) \
       || (defined(_POSIX_C_SOURCE) && _POSIX_C_SOURCE >= 200112L) \
       || (defined(_POSIX_VERSION) && _POSIX_VERSION >= 200112L) \
       || (defined(_POSIX2_VERSION) && _POSIX2_VERSION >= 200112L)
