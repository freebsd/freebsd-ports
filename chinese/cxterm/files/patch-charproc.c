--- cxterm/charproc.c.orig	Fri Oct 25 11:49:49 2002
+++ cxterm/charproc.c	Fri Oct 25 11:52:44 2002
@@ -108,8 +108,6 @@
 
 extern Widget toplevel;
 extern void exit();
-extern char *malloc();
-extern char *realloc();
 
 static void VTallocbuf();
 static int finput();
