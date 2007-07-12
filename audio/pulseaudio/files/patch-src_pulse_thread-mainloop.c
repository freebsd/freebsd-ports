--- src/pulse/thread-mainloop.c.orig	Thu Jul 12 00:01:48 2007
+++ src/pulse/thread-mainloop.c	Thu Jul 12 00:03:32 2007
@@ -30,6 +30,11 @@
 #include <signal.h>
 #include <stdio.h>
 
+#ifdef HAVE_PTHREAD
+#include <pthread.h>
+#include <signal.h>
+#endif
+
 #ifdef HAVE_SYS_POLL_H
 #include <sys/poll.h>
 #else
