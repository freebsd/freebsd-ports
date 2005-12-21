--- main.c.orig	Tue Dec 20 22:31:20 2005
+++ main.c	Tue Dec 20 22:35:22 2005
@@ -237,7 +237,9 @@
 #endif
 #else /* } !SYSV { */			/* BSD systems */
 #ifndef linux
+#ifndef USE_POSIX_TERMIOS
 #include <sgtty.h>
+#endif
 #endif
 #include <sys/resource.h>
 #define HAS_UTMP_UT_HOST
