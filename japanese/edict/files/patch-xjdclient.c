--- xjdclient.c.orig	2024-09-30 19:41:16.980011000 +0100
+++ xjdclient.c	2024-09-30 19:42:00.456457000 +0100
@@ -26,6 +26,7 @@
 
 #include <stdio.h>
 #include <ctype.h>
+#include <errno.h>
 #include <string.h>
 #include <sys/types.h>
 #include <sys/socket.h>
@@ -40,7 +41,6 @@
 
 #define CVERBOSE 0
 int chk_cnt=0;
-extern int errno;
 unsigned char host[51] = {"localhost"};
 unsigned char yn[2];
 unsigned int portno = XJ_PORTNO;
