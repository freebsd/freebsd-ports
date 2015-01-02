--- src/gldit/cairo-dock-file-manager.c.orig	2014-11-22 18:39:10.000000000 +0200
+++ src/gldit/cairo-dock-file-manager.c	2014-11-22 18:41:30.000000000 +0200
@@ -21,7 +21,11 @@
 #include <string.h>      // memset
 #include <sys/stat.h>    // stat
 #include <fcntl.h>  // open
+#ifndef __FreeBSD__
 #include <sys/sendfile.h>  // sendfile
+#else
+#include <sys/socket.h>
+#endif
 #include <errno.h>  // errno
 
 #include "gldi-config.h"
