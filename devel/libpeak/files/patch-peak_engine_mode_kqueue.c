--- peak/engine_mod_kqueue.c.orig	2013-02-11 09:50:18.000000000 +0100
+++ peak/engine_mod_kqueue.c	2013-02-11 09:51:01.000000000 +0100
@@ -47,6 +47,9 @@
 #include <time.h>
 #include <unistd.h>
 #include <sys/event.h>
+#ifdef HAVE_SYS_SIGNAL_H
+#include <sys/signal.h>
+#endif
 #ifdef HAVE_SIGNAL_H
 #include <signal.h>
 #endif
