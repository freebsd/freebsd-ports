$FreeBSD$

--- src/VBox/Runtime/r0drv/freebsd/the-freebsd-kernel.h	2012-12-19 10:27:29.000000000 -0800
+++ src/VBox/Runtime/r0drv/freebsd/the-freebsd-kernel.h	2013-03-20 19:10:15.854804053 -0700
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
