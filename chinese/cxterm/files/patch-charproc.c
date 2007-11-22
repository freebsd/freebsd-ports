--- cxterm/charproc.c.orig	2007-11-22 14:31:36.000000000 +0100
+++ cxterm/charproc.c	2007-11-22 14:39:45.000000000 +0100
@@ -77,6 +77,7 @@
 #include <X11/Xmu/CharSet.h>
 #include <X11/Xmu/Converters.h>
 #include <stdio.h>
+#include <stdlib.h>
 #include <errno.h>
 #include <setjmp.h>
 #include <ctype.h>
@@ -108,8 +109,6 @@
 
 extern Widget toplevel;
 extern void exit();
-extern char *malloc();
-extern char *realloc();
 
 static void VTallocbuf();
 static int finput();
@@ -1672,7 +1671,7 @@
 	write_mask = ptymask();
 	select_timeout.tv_sec = 0;
 	select_timeout.tv_usec = 0;
-	i = select(max_plus1, &select_mask, &write_mask, (int *)NULL,
+	i = select(max_plus1, (fd_set *)&select_mask, (fd_set *)&write_mask, (fd_set *)NULL,
 		   QLength(screen->display) ? &select_timeout
 		   : (struct timeval *) NULL);
 	if (i < 0) {
