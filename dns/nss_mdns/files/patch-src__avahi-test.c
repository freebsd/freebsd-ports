--- src/avahi-test.c.orig	Sat Aug  6 00:51:50 2005
+++ src/avahi-test.c	Sat Jan 20 14:34:44 2007
@@ -19,6 +19,7 @@
   USA.
 ***/
 
+#include <sys/socket.h>
 #include <arpa/inet.h>
 #include <stdio.h>
 
