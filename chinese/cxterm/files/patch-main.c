--- cxterm/main.c.orig	Fri Oct 25 11:44:46 2002
+++ cxterm/main.c	Fri Oct 25 11:47:13 2002
@@ -223,6 +223,9 @@
 #ifndef linux
 #include <sgtty.h>
 #endif
+#ifdef __FreeBSD__
+#define USE_POSIX_WAIT
+#endif
 #include <sys/resource.h>
 #define HAS_UTMP_UT_HOST
 #define HAS_BSD_GROUPS
