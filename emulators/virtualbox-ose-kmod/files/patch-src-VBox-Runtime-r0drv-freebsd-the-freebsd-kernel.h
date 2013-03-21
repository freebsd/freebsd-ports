$FreeBSD$

--- src/VBox/Runtime/r0drv/freebsd/the-freebsd-kernel.h	2012-12-19 10:27:29.000000000 -0800
+++ src/VBox/Runtime/r0drv/freebsd/the-freebsd-kernel.h	2013-03-20 14:50:35.330638254 -0700
@@ -50,6 +50,7 @@
 #include <sys/unistd.h>
 #include <sys/kthread.h>
 #include <sys/lock.h>
+#include <sys/rwlock.h>
 #include <sys/mutex.h>
 #include <sys/sched.h>
 #include <sys/callout.h>
