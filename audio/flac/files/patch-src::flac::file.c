$FreeBSD$
--- src/flac/file.c.orig	Thu Jun  7 21:50:01 2001
+++ src/flac/file.c	Thu Jun  7 21:50:20 2001
@@ -20,6 +20,7 @@
 #include <sys/utime.h> /* for utime() */
 #include <io.h> /* for chmod() */
 #else
+#include <sys/types.h>
 #include <utime.h> /* for utime() */
 #include <unistd.h> /* for chown() */
 #endif
