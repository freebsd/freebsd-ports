--- src/lib/machines/freebsd/5/80x86/startup/xpg3.h.orig	2009-08-13 22:00:40.000000000 +0200
+++ src/lib/machines/freebsd/5/80x86/startup/xpg3.h	2009-08-13 22:08:01.000000000 +0200
@@ -8,6 +8,8 @@
 #define __semun_defined			1
 #define __WRONG_XPG3_TERMIOS_H
 #define __WRONG_XPG3_SYS_SEM_H
+#define __WRONG_XPG3_SYS_SHM_H
+#define __WRONG_XPG3_SYS_SHM_H_SHM_PROTO
 
 #include <limits.h>
 #undef _POSIX_CHILD_MAX
