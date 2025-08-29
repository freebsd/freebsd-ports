--- src/libs/xpcom18a4/nsprpub/pr/src/pthreads/ptsynch.c.orig	2025-01-21 20:03:59.000000000 +0700
+++ src/libs/xpcom18a4/nsprpub/pr/src/pthreads/ptsynch.c	2025-01-23 01:00:59.324267000 +0700
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
