--- xltwavplay.c.orig	1999-12-04 00:06:42 UTC
+++ xltwavplay.c
@@ -59,7 +59,9 @@
 #include <time.h>
 #include <signal.h>
 #include <string.h>
+#ifndef FREEBSD
 #include <getopt.h>
+#endif
 #include <errno.h>
 #include <sys/types.h>
 #include <sys/ipc.h>
