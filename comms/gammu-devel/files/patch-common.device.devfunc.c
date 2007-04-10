--- common/device/devfunc.c.orig	Fri Feb 23 23:50:01 2007
+++ common/device/devfunc.c	Tue Apr 10 23:46:39 2007
@@ -18,6 +18,8 @@
 
 #include <string.h>
 #include <fcntl.h>
+#include <sys/stat.h>
+#include <sys/socket.h>
 #ifdef WIN32
 #  include <io.h>
 #else
