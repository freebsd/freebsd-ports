--- src/VBox/Runtime/r0drv/freebsd/the-freebsd-kernel.h.orig	2012-12-19 20:51:59.000000000 +0100
+++ src/VBox/Runtime/r0drv/freebsd/the-freebsd-kernel.h	2013-05-10 12:40:19.000000000 +0200
@@ -50,6 +50,9 @@
 #include <sys/unistd.h>
 #include <sys/kthread.h>
 #include <sys/lock.h>
+#if __FreeBSD_version >= 1000030
+#include <sys/rwlock.h>
+#endif
 #include <sys/mutex.h>
 #include <sys/sched.h>
 #include <sys/callout.h>
