--- libgammu/device/devfunc.c.orig	Fri Feb 23 23:50:01 2007
+++ libgammu/device/devfunc.c	Tue Apr 10 23:46:39 2007
@@ -19,6 +19,8 @@
 #include <string.h>
 #include <fcntl.h>
 #include <stdlib.h>
+#include <sys/stat.h>
+#include <sys/socket.h>
 #ifdef WIN32
 #  include <io.h>
 #else
