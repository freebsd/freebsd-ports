--- comp_thr.c.orig	Thu Aug 22 20:32:10 2002
+++ comp_thr.c	Thu Aug 22 20:32:25 2002
@@ -16,7 +16,7 @@
 #include <time.h>
 
 #ifdef UNIX
-#if !defined(__NetBSD__) && !defined(MacOSX)
+#if !defined(__FreeBSD__) && !defined(__NetBSD__) && !defined(MacOSX)
 #include <values.h>
 #else
 #include <limits.h>
