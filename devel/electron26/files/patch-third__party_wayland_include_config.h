--- third_party/wayland/include/config.h.orig	2023-10-09 02:57:22 UTC
+++ third_party/wayland/include/config.h
@@ -25,11 +25,14 @@
 
 #undef HAVE_SYS_PROCCTL_H
 
+#if defined(__FreeBSD__)
+#define HAVE_SYS_UCRED_H
+#else
 #undef HAVE_SYS_UCRED_H
+#endif
 
 #define HAVE_XUCRED_CR_PID 0
 
 #define PACKAGE "wayland"
 
 #define PACKAGE_VERSION "1.21.0"
-
