--- ./code/qcommon/common.c.orig	Wed Apr 26 08:27:12 2006
+++ ./code/qcommon/common.c	Sun Jun 11 17:26:26 2006
@@ -25,6 +25,7 @@
 #include "qcommon.h"
 #include <setjmp.h>
 #ifndef _WIN32
+#include <sys/types.h>
 #include <netinet/in.h>
 #include <sys/stat.h> // umask
 #else
