--- src/pulse/thread-mainloop.c.orig	2008-01-01 17:23:28.000000000 -0500
+++ src/pulse/thread-mainloop.c	2008-01-01 17:25:00.000000000 -0500
@@ -27,6 +27,9 @@
 #endif
 
 #include <signal.h>
+#ifndef OS_IS_WIN32
+#include <pthread.h>
+#endif
 #include <stdio.h>
 
 #ifdef HAVE_POLL_H
