--- complib.c.orig	Thu Aug 22 20:33:57 2002
+++ complib.c	Thu Aug 22 20:34:07 2002
@@ -29,7 +29,7 @@
 #include <ctype.h>
 #include <time.h>
 #ifdef UNIX
-#if !defined(__NetBSD__) && !defined(MacOSX)
+#if !defined(__FreeBSD__) && !defined(__NetBSD__) && !defined(MacOSX)
 #include <values.h>
 #else
 #include <limits.h>
