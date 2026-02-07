--- ./tremulous-1.1.0-src/src/qcommon/common.c.orig	Tue Feb 28 20:11:58 2006
+++ ./tremulous-1.1.0-src/src/qcommon/common.c	Wed Jun  7 16:57:12 2006
@@ -26,6 +26,7 @@
 #include "qcommon.h"
 #include <setjmp.h>
 #ifndef _WIN32
+#include <sys/types.h>
 #include <netinet/in.h>
 #include <sys/stat.h> // umask
 #else
