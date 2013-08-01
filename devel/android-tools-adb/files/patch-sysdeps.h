--- sysdeps.h.orig	2013-08-01 17:13:17.000000000 +0800
+++ sysdeps.h	2013-08-01 17:13:39.000000000 +0800
@@ -264,6 +264,8 @@
 #include <cutils/properties.h>
 #include <cutils/misc.h>
 #include <signal.h>
+#include <sys/types.h>
+#include <sys/socket.h>
 #include <sys/wait.h>
 #include <sys/stat.h>
 #include <fcntl.h>
