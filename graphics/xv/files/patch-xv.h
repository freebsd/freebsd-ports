--- xv.h.orig	2009-05-17 12:01:21.000000000 +0200
+++ xv.h	2009-05-17 12:02:58.000000000 +0200
@@ -158,7 +159,7 @@
 
 #ifndef VMS
 #  include <errno.h>
-#  ifndef __NetBSD__
+#  if !defined(__NetBSD__) && !defined(__FreeBSD__)
 #    if !(defined __GLIBC__ && __GLIBC__ >= 2)
        extern int   errno;         /* SHOULD be in errno.h, but often isn't */
        extern char *sys_errlist[]; /* this too... */
