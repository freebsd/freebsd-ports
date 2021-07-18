--- erts/etc/unix/run_erl.c.orig	2015-03-31 12:32:52 UTC
+++ erts/etc/unix/run_erl.c
@@ -73,9 +73,6 @@
 #ifdef HAVE_UTMP_H
 #  include <utmp.h>
 #endif
-#ifdef HAVE_UTIL_H
-#  include <util.h>
-#endif
 #ifdef HAVE_SYS_IOCTL_H
 #  include <sys/ioctl.h>
 #endif
