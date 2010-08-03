--- Source/include/NCSMalloc.h.orig	2009-04-05 21:19:51.000000000 +0400
+++ Source/include/NCSMalloc.h	2009-04-05 21:21:13.000000000 +0400
@@ -43,7 +43,9 @@
 
 #else /* MACINTOSH */
 
+#ifndef FREEBSD
 #include <malloc.h>
+#endif
 
 #if defined SOLARIS || defined LINUX || defined HPUX
 #include <string.h>
