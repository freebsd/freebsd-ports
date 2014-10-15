
$FreeBSD$

Merged in #1340 upstream.

--- mono/utils/mono-threads-freebsd.c.orig
+++ mono/utils/mono-threads-freebsd.c
@@ -2,6 +2,7 @@
 
 #if defined(__FreeBSD__)
 
+#include <mono/utils/mono-threads.h>
 #include <pthread.h>
 #include <pthread_np.h>
 
