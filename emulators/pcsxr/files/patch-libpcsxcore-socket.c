--- libpcsxcore/socket.c.orig	2011-01-21 18:06:44.210865888 +0100
+++ libpcsxcore/socket.c	2011-01-21 18:07:58.238538120 +0100
@@ -23,6 +23,7 @@
 #include "socket.h"
 
 #ifndef _WIN32
+#include <sys/types.h>
 #include <sys/socket.h>
 #include <sys/ioctl.h>
 #include <arpa/inet.h>
