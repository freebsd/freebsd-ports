--- stty.c.orig	Wed Sep 23 01:22:53 1998
+++ stty.c	Sat Oct 11 22:25:59 2003
@@ -309,7 +309,7 @@
 chld_changed()
 {
 	int cpid;
-#if defined(_AIX) || defined(SVR4)
+#if defined(_AIX) || defined(SVR4) || defined(__FreeBSD__)
 	int statusp;
 #else
 	union wait statusp;
