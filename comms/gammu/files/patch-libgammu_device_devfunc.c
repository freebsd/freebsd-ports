--- libgammu/device/devfunc.c.orig	2015-12-08 10:38:12 UTC
+++ libgammu/device/devfunc.c
@@ -15,6 +15,8 @@
 #include <string.h>
 #include <fcntl.h>
 #include <stdlib.h>
+#include <sys/stat.h>
+#include <sys/socket.h>
 #ifdef WIN32
 #  include <winsock2.h>
 #  include <io.h>
