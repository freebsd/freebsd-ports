--- EMULib/NetUnix.c.orig	2008-05-26 05:26:55.000000000 +0000
+++ EMULib/NetUnix.c	2008-05-26 05:28:16.000000000 +0000
@@ -17,6 +17,8 @@
 #include <stdio.h>
 #include <netdb.h>
 #include <errno.h>
+#include <netinet/in.h>
+#include <sys/types.h>
 #include <sys/ioctl.h>
 #include <sys/socket.h>
 
