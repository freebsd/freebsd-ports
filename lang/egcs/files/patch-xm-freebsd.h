--- gcc/config/xm-freebsd.h.orig	1999/08/26 09:29:27	1.1.1.2
+++ gcc/config/xm-freebsd.h	1999/08/30 10:12:33	1.4
@@ -22,3 +22,16 @@
    running FreeBSD.  This file should not be specified as $xm_file itself;
    instead $xm_file should be CPU/xm-freebsd.h, which should include both
    CPU/xm-CPU.h and this file xm-freebsd.h.  */
+
+#ifndef HAVE_ATEXIT
+#define HAVE_ATEXIT
+#endif
+
+/* Tell gcc and collect2 that FreeBSD targets support putenv(3).  */
+#define HAVE_PUTENV
+
+/* We have _sys_siglist, but the declaration in <signal.h> conflicts with
+   the declarations in collect2.c and mips-tfile.c, so disable the declarations
+   in those files.  */
+
+#define SYS_SIGLIST_DECLARED
