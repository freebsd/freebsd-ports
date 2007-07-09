--- src/pulsecore/mutex-posix.c.orig	Sun Jul  8 18:13:31 2007
+++ src/pulsecore/mutex-posix.c	Sun Jul  8 18:13:59 2007
@@ -28,7 +28,8 @@
 #include <assert.h>
 #include <pthread.h>
 
-#include <atomic_ops.h>
+#include <sys/cdefs.h>
+#include <machine/atomic.h>
 
 #include <pulse/xmalloc.h>
 
