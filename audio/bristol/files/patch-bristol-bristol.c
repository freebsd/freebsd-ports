--- bristol/bristol.c.orig	2012-04-27 13:04:28.000000000 +0200
+++ bristol/bristol.c	2012-09-24 15:43:08.299853839 +0200
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
