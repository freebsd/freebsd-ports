--- compacc.c.orig	Thu Aug 22 20:30:30 2002
+++ compacc.c	Thu Aug 22 20:30:43 2002
@@ -11,7 +11,7 @@
 #if defined(UNIX) || defined(MSDOS)
 #include <sys/types.h>
 #endif
-#if !defined(__MWERKS__) && !defined(MacOSX)
+#if !defined(__FreeBSD__) && !defined(__MWERKS__) && !defined(MacOSX)
 #include <values.h>
 #else
 #include <limits.h>
