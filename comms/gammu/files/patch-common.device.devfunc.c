--- libgammu/device/devfunc.c.orig	2010-07-12 15:51:05.000000000 +0400
+++ libgammu/device/devfunc.c	2011-01-28 13:21:17.938543134 +0300
@@ -15,6 +15,8 @@
 #include <string.h>
 #include <fcntl.h>
 #include <stdlib.h>
+#include <sys/stat.h>
+#include <sys/socket.h>
 #ifdef WIN32
 #  include <winsock2.h>
 #  include <io.h>
