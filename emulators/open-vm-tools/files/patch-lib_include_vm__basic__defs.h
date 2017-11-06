--- lib/include/vm_basic_defs.h.orig	2017-02-24 22:15:37 UTC
+++ lib/include/vm_basic_defs.h
@@ -76,7 +76,11 @@
 #include "vm_basic_types.h" // For INLINE.
 
 /* Checks for FreeBSD, filtering out VMKERNEL. */
-#define __IS_FREEBSD__ (!defined(VMKERNEL) && defined(__FreeBSD__))
+#if !defined(VMKERNEL) && defined(__FreeBSD__)
+#define __IS_FREEBSD__ 1
+#else
+#define __IS_FREEBSD__ 0
+#endif
 #define __IS_FREEBSD_VER__(ver) (__IS_FREEBSD__ && __FreeBSD_version >= (ver))
 
 #if defined _WIN32 && defined USERLEVEL
