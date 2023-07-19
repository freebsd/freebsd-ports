--- lib/panic/panic.c.orig	2023-06-12 23:13:35 UTC
+++ lib/panic/panic.c
@@ -34,6 +34,8 @@
 #  include <signal.h>
 #  ifdef __APPLE__
 #    include <TargetConditionals.h>
+#  endif
+#  if defined (__APPLE__) || defined (__FreeBSD__)
 #    include <sys/types.h>
 #    include <sys/sysctl.h>
 #  endif
