--- metadata/rb-metadata-dbus-client.c.orig	Mon Apr 17 03:08:10 2006
+++ metadata/rb-metadata-dbus-client.c	Mon Apr 17 03:08:25 2006
@@ -53,6 +53,7 @@
 #include <unistd.h>
 #include <sys/types.h>
 #include <sys/wait.h>
+#include <signal.h>
 #include <string.h>
 #include <stdlib.h>
 
