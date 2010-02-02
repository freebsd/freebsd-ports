--- src/filelock.c.orig	2009-06-21 07:38:14.000000000 +0300
+++ src/filelock.c	2010-01-23 11:34:48.414989942 +0200
@@ -62,7 +62,9 @@
 
 #ifdef CLASH_DETECTION
 
+#ifdef HAVE_UTMP_H
 #include <utmp.h>
+#endif
 
 #if !defined (S_ISLNK) && defined (S_IFLNK)
 #define S_ISLNK(m) (((m) & S_IFMT) == S_IFLNK)
