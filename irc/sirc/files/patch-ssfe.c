--- ssfe.c.orig	1998-03-10 04:55:53.000000000 -0800
+++ ssfe.c	2009-03-04 22:46:01.000000000 -0800
@@ -23,6 +23,7 @@
 #include <fcntl.h>
 #include <unistd.h>
 #include <signal.h>
+#include <string.h>
 #include <errno.h>
 
 #ifdef USE_SGTTY
@@ -106,7 +107,6 @@
 int ansi_cs = 0;
 
 fd_set ready, result;
-extern int errno;
 
 #ifdef __GNUC__
 extern unsigned char *tgoto(unsigned char *cm, int col, int line);
