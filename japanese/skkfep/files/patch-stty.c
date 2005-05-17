--- stty.c.orig	Wed Sep  3 08:49:32 2003
+++ stty.c	Mon May 16 14:18:07 2005
@@ -306,7 +306,7 @@
 {
 	int cpid;
 /* #ifdef _AIX */
-#if defined(_AIX) || defined(NECEWS) || defined(SOLARIS2)
+#if defined(_AIX) || defined(NECEWS) || defined(SOLARIS2) || defined(__FreeBSD__)
 	int statusp;
 	reset_tty_without_close();
 	cpid = wait(&statusp);
