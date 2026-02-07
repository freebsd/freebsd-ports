--- peak/signal.c.orig	2013-02-11 09:43:19.000000000 +0100
+++ peak/signal.c	2013-02-11 09:49:07.000000000 +0100
@@ -45,6 +45,9 @@
 #include <stdlib.h>
 #include <stdio.h>
 #include <string.h>
+#ifdef HAVE_SYS_SIGNAL_H
+#include <sys/signal.h>
+#endif
 #ifdef HAVE_SIGNAL_H
 #include <signal.h>
 #endif
