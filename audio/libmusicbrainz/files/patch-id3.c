--- lib/bitzi/id3.c.orig	Sat May 19 14:47:54 2001
+++ lib/bitzi/id3.c	Sat May 19 14:48:09 2001
@@ -13,6 +13,7 @@
 #include <stdlib.h>
 #include <assert.h>
 #include <errno.h>
+#include <sys/types.h>
 #ifdef WIN32
 #include <winsock.h>
 #else
