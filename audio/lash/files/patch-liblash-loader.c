--- liblash/loader.c.orig	Sat Jan 13 15:13:46 2007
+++ liblash/loader.c	Sat Jan 13 15:14:43 2007
@@ -25,6 +25,7 @@
 #include <errno.h>
 #include <unistd.h>
 #include <signal.h>
+#include <fcntl.h>
 
 #include <lash/lash.h>
 #include <lash/loader.h>
