--- common/device/devfunc.c.orig	Sun Nov 20 22:01:18 2005
+++ common/device/devfunc.c	Thu Jan 19 18:35:48 2006
@@ -17,6 +17,8 @@
  */
 
 #include <string.h>
+#include <sys/stat.h>
+#include <sys/socket.h>
 #ifdef WIN32
 #  include <io.h>
 #else
