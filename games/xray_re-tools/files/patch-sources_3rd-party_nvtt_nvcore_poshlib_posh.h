--- sources/3rd-party/nvtt/nvcore/poshlib/posh.h.orig	2018-09-02 12:42:44 UTC
+++ sources/3rd-party/nvtt/nvcore/poshlib/posh.h
@@ -293,6 +293,11 @@ Metrowerks:
 #  define POSH_OS_STRING "Linux"
 #endif
 
+#if defined __FreeBSD__
+#  define POSH_OS_LINUX 1
+#  define POSH_OS_STRING "FreeBSD"
+#endif
+
 #if defined __CYGWIN32__
 #  define POSH_OS_CYGWIN32 1
 #  define POSH_OS_STRING "Cygwin"
