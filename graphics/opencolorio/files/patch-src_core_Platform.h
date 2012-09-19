--- src/core/Platform.h.orig	2012-06-21 20:18:57.343827187 +0930
+++ src/core/Platform.h	2012-06-21 20:20:38.915828064 +0930
@@ -85,7 +85,9 @@
 
 // linux/unix/posix
 #include <stdlib.h>
+#if !defined(__FreeBSD__)
 #include <alloca.h>
+#endif
 #include <string.h>
 #include <pthread.h>
 // OS for spinlock
