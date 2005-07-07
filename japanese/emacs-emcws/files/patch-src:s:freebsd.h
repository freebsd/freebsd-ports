--- src/s/freebsd.h.orig	Tue Feb 20 19:52:17 2001
+++ src/s/freebsd.h	Mon Feb 18 11:51:50 2002
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
