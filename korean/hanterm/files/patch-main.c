--- main.c.orig	Fri Oct 25 12:00:42 2002
+++ main.c	Fri Oct 25 12:01:43 2002
@@ -224,6 +224,9 @@
 #ifndef linux
 #include <sgtty.h>
 #endif
+#ifdef __FreeBSD__
+#define USE_POSIX_WAIT
+#endif
 #include <sys/resource.h>
 #define HAS_UTMP_UT_HOST
 #define HAS_BSD_GROUPS
