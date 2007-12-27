--- mime.c.orig	2007-11-11 17:58:01.000000000 +0900
+++ mime.c	2007-11-11 17:59:42.000000000 +0900
@@ -54,6 +54,8 @@
 static int got_EOR;
 static int addQY;
 
+static scan_charset(char *header, char *chset, int len);
+
 #define DEBUG	syslog_DEBUG
 
 #define O_HEAD	1
