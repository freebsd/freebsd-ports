--- ../desktop/source/pkgchk/pkgchk_misc.h.orig	Wed Mar  5 20:51:46 2003
+++ ../desktop/source/pkgchk/pkgchk_misc.h	Wed Mar  5 20:52:45 2003
@@ -208,6 +208,8 @@
 #define THIS_PLATFORM_PATH "/macosx_powerpc.plt"
 #elif defined (NETBSD) && defined (SPARC)
 #define THIS_PLATFORM_PATH "/netbsd_sparc.plt"
+#elif defined (FREEBSD) && defined (INTEL)
+#define THIS_PLATFORM_PATH "/freebsd_x86.plt"
 #else
 #error "unknown platform"
 insert your platform identifier above; inserted for the case the preprocessor ignores error
