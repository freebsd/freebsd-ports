--- src/libs/xpcom18a4/nsprpub/pr/src/pthreads/ptsynch.c.orig	2025-08-13 19:56:47 UTC
+++ src/libs/xpcom18a4/nsprpub/pr/src/pthreads/ptsynch.c
@@ -45,6 +45,10 @@
 #include <string.h>
 #include <pthread.h>
 #include <sys/time.h>
+#ifdef FREEBSD
+#include <sys/param.h>
+#endif
+
 #include <errno.h>
 
 #include <iprt/asm.h>
