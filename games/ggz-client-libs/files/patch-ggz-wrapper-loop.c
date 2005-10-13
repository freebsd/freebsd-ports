--- ggz-wrapper/loop.c.orig	Wed Aug  3 05:34:53 2005
+++ ggz-wrapper/loop.c	Fri Oct  7 13:06:53 2005
@@ -34,6 +34,7 @@
 #include <ggz.h>
 #include <unistd.h>
 #include <stdlib.h>
+#include <string.h>
 #include <sys/time.h>
 #include <sys/types.h>
 #ifdef HAVE_WINSOCK2_H
