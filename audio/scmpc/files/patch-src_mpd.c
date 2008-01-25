--- src/mpd.c.orig	Wed Jan 16 12:49:48 2008
+++ src/mpd.c	Sun Dec  3 02:59:18 2006
@@ -26,6 +26,7 @@
 #include <unistd.h>
 #include <pthread.h>
 #include <sys/types.h>
+#include <sys/select.h>
 #include <signal.h>
 #include <math.h>
 #include <string.h>
