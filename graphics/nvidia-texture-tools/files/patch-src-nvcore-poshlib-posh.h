--- src/nvcore/poshlib/posh.h.orig	2010-05-15 09:12:05 UTC
+++ src/nvcore/poshlib/posh.h
@@ -293,6 +293,11 @@ Metrowerks:
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
