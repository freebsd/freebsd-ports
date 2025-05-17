--- third_party/wayland/include/config.h.orig	2024-02-21 00:21:13 UTC
+++ third_party/wayland/include/config.h
@@ -9,7 +9,14 @@
 
 #define HAVE_BROKEN_MSG_CMSG_CLOEXEC 0
 
+#if defined(__FreeBSD__)
+#include <osreldate.h>
+#if defined(__FreeBSD_version) && __FreeBSD_version < 1300048
+#undef HAVE_MEMFD_CREATE
+#else
 #define HAVE_MEMFD_CREATE
+#endif
+#endif
 
 #define HAVE_MKOSTEMP
 
@@ -25,7 +32,11 @@
 
 #undef HAVE_SYS_PROCCTL_H
 
+#if defined(__FreeBSD__)
+#define HAVE_SYS_UCRED_H
+#else
 #undef HAVE_SYS_UCRED_H
+#endif
 
 #define HAVE_XUCRED_CR_PID 0
 
