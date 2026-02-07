--- bristol/bristol.c.orig	2012-04-27 11:04:28 UTC
+++ bristol/bristol.c
@@ -27,7 +27,11 @@
 #include <unistd.h>
 #include <pthread.h>
 #include <sys/types.h>
+#ifdef __FreeBSD__
+#include <sys/wait.h>
+#else
 #include <wait.h>
+#endif
 
 #if defined(linux)
 #include <sched.h>
