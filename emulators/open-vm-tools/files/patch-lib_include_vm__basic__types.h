--- lib/include/vm_basic_types.h.orig	2018-03-30 18:44:35 UTC
+++ lib/include/vm_basic_types.h
@@ -418,6 +418,7 @@ typedef int64 VmTimeVirtualClock;  /* Virtual Clock ke
       #endif
    #elif defined(__linux__) || \
         (defined(__FreeBSD__) && (__FreeBSD__ + 0))\
+      || (defined(__clang__)) \
       || (defined(_POSIX_C_SOURCE) && _POSIX_C_SOURCE >= 200112L) \
       || (defined(_POSIX_VERSION) && _POSIX_VERSION >= 200112L) \
       || (defined(_POSIX2_VERSION) && _POSIX2_VERSION >= 200112L)
