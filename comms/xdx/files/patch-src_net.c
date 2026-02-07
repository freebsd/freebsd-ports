- workaround for https://github.com/N0NB/xdx/issues/12

--- src/net.c.orig	2022-09-11 15:53:06 UTC
+++ src/net.c
@@ -62,7 +62,7 @@
 #include <errno.h>
 #include <fcntl.h>
 #include <netdb.h>
-#include <resolv.h>
+//#include <resolv.h>
 #include <signal.h>
 #include <stdlib.h>
 #include <string.h>
