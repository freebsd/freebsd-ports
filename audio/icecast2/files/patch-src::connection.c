--- src/connection.c.orig	Mon Aug  5 20:39:21 2002
+++ src/connection.c	Mon Aug  5 20:40:08 2002
@@ -18,6 +18,7 @@
  *
  */
 
+#include <sys/types.h>
 #ifdef HAVE_CONFIG_H
 #ifdef _WIN32
 #include <win32config.h>
@@ -42,7 +43,6 @@
 #include <unistd.h>
 #endif
 
-#include <sys/types.h>
 #include <ctype.h>
 #include <errno.h>
 #include <time.h>
