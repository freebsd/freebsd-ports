--- src/s/freebsd.h.orig	Tue Feb 20 19:52:17 2001
+++ src/s/freebsd.h	Sat Nov 16 21:46:03 2002
@@ -68,6 +68,11 @@
 #define LIBS_SYSTEM -lutil
 #if __FreeBSD_version < 400000
 #define LIBS_TERMCAP -ltermcap
+#else
+#ifdef HAVE_LIBNCURSES
+#define TERMINFO
+#define LIBS_TERMCAP -lncurses
+#endif
 #endif
 
 #define SYSV_SYSTEM_DIR
@@ -220,3 +225,7 @@
    of sigblock says it is obsolete.  */
 
 #define POSIX_SIGNALS		1
+
+#if __FreeBSD_version >= 500000
+#define LD_SWITCH_SYSTEM_TEMACS -znocombreloc
+#endif
