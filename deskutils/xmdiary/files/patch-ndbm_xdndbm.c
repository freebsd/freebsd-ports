--- ndbm/xdndbm.c.orig	Tue Jun 27 03:55:51 1995
+++ ndbm/xdndbm.c	Mon Sep 29 01:53:52 1997
@@ -50,8 +50,10 @@
 static  int delitem();
 static  int additem();
 
+#ifndef __FreeBSD__
 extern  int errno;
 extern  long lseek();
+#endif
 
 #ifdef DEBUG
 static chkblk(char buf[PBLKSIZ]);
