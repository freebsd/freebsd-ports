--- src/doodle/tree.c.orig	Wed Jan  5 23:24:27 2005
+++ src/doodle/tree.c	Fri Jul 22 15:48:57 2005
@@ -38,6 +38,7 @@
 
 #include "config.h"
 #include "doodle.h"
+#include <sys/types.h>
 #include <netinet/in.h>
 #include <stdarg.h>
 #include <stdlib.h>
@@ -1815,7 +1816,7 @@
     /* make certain that the dirty marker is on
        disk... */
     flush_buffer(ret->fd);
-    fdatasync(ret->fd->fd);
+    fsync(ret->fd->fd);
     ret->modified = 1;
   }
   
