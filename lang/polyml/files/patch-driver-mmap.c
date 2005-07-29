--- mmap.c.orig	Fri Jun 10 09:54:34 2005
+++ mmap.c	Fri Jun 10 09:55:57 2005
@@ -60,7 +60,7 @@
 #include <sys/uio.h>
 #include <sys/param.h>
 #include <unistd.h> 
-#ifdef MACOSX
+#if (defined(FREEBSD) || defined(MACOSX))
 #include <limits.h>
 #else
 #include <values.h> /* FreeBSD warns about this but it's needed in Solaris. */
