--- src/sock.c.orig	Mon Aug  5 20:57:27 2002
+++ src/sock.c	Mon Aug  5 20:57:48 2002
@@ -19,6 +19,7 @@
  *
  */
 
+#include <sys/types.h>
 #ifdef HAVE_CONFIG_H
 #ifdef _WIN32
 #include <win32config.h>
@@ -35,7 +36,6 @@
 
 #include "definitions.h"
 
-#include <sys/types.h>
 #include <ctype.h>
 
 #ifdef HAVE_UNISTD_H
