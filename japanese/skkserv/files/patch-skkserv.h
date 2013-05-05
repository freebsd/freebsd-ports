--- skkserv/skkserv.h.orig	1997-01-21 04:16:36.000000000 +0900
+++ skkserv/skkserv.h	2013-05-05 23:59:34.000000000 +0900
@@ -37,6 +37,8 @@
 /* Necessary for SunOS 3.x and maybe other old systems */
 
 #include	<stdio.h>
+#include	<stdlib.h>
+#include	<string.h>
 
 #include	<sys/types.h>
 #ifdef HAVE_SYS_IOCTL_H
@@ -44,9 +46,12 @@
 #endif
 #include	<sys/socket.h>
 #include	<netinet/in.h>
+#include	<arpa/inet.h>
 #include	<netdb.h>
 #include	<signal.h>
 #include	<errno.h>
+#include	<pwd.h>
+#include	<unistd.h>
 
 #ifndef DEFAULT_JISYO
 #define DEFAULT_JISYO 	"/usr/local/share/emacs/SKK-JISYO.L"	
