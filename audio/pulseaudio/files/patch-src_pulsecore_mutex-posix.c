--- src/pulsecore/mutex-posix.c.orig	2007-05-12 19:21:39.000000000 -0400
+++ src/pulsecore/mutex-posix.c	2007-07-09 01:28:06.000000000 -0400
@@ -28,7 +28,9 @@
 #include <assert.h>
 #include <pthread.h>
 
-#include <atomic_ops.h>
+#include <sys/types.h>
+#include <sys/cdefs.h>
+#include <machine/atomic.h>
 
 #include <pulse/xmalloc.h>
 
