--- vm/config.h.orig	Thu Nov 20 20:04:10 2003
+++ vm/config.h	Thu Nov 20 20:04:25 2003
@@ -15,6 +15,7 @@
 
 #ifdef unix
 
+#include <time.h>
 #include <utime.h>
 #include <errno.h>
 #include <sys/types.h>
