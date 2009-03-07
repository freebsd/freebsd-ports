--- src/nvcore/poshlib/posh.h.orig	2008-12-01 11:04:27.000000000 +0300
+++ src/nvcore/poshlib/posh.h	2009-03-06 22:36:38.000000000 +0300
@@ -293,6 +293,11 @@
 #  define POSH_OS_STRING "Linux"
 #endif
 
+#if defined __FreeBSD__
+#  define POSH_OS_FREEBSD 1
+#  define POSH_OS_STRING "FreeBSD"
+#endif
+
 #if defined __CYGWIN32__
 #  define POSH_OS_CYGWIN32 1
 #  define POSH_OS_STRING "Cygwin"
