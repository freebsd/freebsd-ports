--- ../../j2se/src/solaris/hpi/native_threads/src/threads_md.c.orig	Thu Mar 13 11:46:02 2003
+++ ../../j2se/src/solaris/hpi/native_threads/src/threads_md.c	Thu Mar 13 11:46:12 2003
@@ -19,7 +19,7 @@
 #include <assert.h>
 #include <setjmp.h>
 #include <signal.h>
-#include <time.h>
+#include <sys/time.h>
 #include <sys/types.h>
 #include <sys/signal.h>
 #include <sys/resource.h>
