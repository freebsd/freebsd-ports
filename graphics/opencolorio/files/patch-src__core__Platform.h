--- ./src/core/Platform.h.orig	2012-04-18 09:38:16.000000000 +0930
+++ ./src/core/Platform.h	2012-10-08 00:20:27.668352332 +1030
@@ -85,7 +85,9 @@
 
 // linux/unix/posix
 #include <stdlib.h>
+#if !defined(__FreeBSD__)
 #include <alloca.h>
+#endif
 #include <string.h>
 #include <pthread.h>
 // OS for spinlock
