--- src/imagemagick.c.orig	Wed Nov 21 13:19:48 2001
+++ src/imagemagick.c	Thu Nov 22 06:12:10 2001
@@ -22,7 +22,7 @@
  * Loading through ImageMagick. *
  ********************************/
 
-#include <fcntl.h>              /* S_IRWXU */
+#include <sys/stat.h>           /* S_IRWXU */
 #include <stdio.h>              /* tmpnam() */
 #include <time.h>               /* time() */
 #include <unistd.h>             /* chdir(), getpid(), unlink() */
