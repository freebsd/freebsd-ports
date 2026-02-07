--- src/xv.h.orig	2023-07-17 01:25:42 UTC
+++ src/xv.h
@@ -183,7 +183,7 @@
 
 #ifndef VMS
 #  include <errno.h>
-#  ifndef __NetBSD__
+#  if !defined(__NetBSD__) && !defined(__FreeBSD__)
 #    if !(defined(__GLIBC__) && __GLIBC__ >= 2) && !defined(__OpenBSD__)
        extern int   errno;         /* SHOULD be in errno.h, but often isn't */
 #      ifndef XV_HAVE_SYSERRLISTDECL
