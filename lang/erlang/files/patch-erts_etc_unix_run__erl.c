--- erts/etc/unix/run_erl.c.orig	2021-09-02 10:21:16 UTC
+++ erts/etc/unix/run_erl.c
@@ -81,9 +81,6 @@
 #ifdef HAVE_LIBUTIL_H
 #  include <libutil.h>
 #endif
-#ifdef HAVE_UTIL_H
-#  include <util.h>
-#endif
 #ifdef HAVE_SYS_IOCTL_H
 #  include <sys/ioctl.h>
 #endif
