--- lib/gpsdisplay.c.orig	Sun Oct 12 16:24:52 2003
+++ lib/gpsdisplay.c	Sun Oct 12 16:23:45 2003
@@ -11,7 +11,7 @@
 #include <stdio.h>
 #include <strings.h>
 
-#ifdef LINUX
+#if defined(LINUX) || defined(__FreeBSD__)
 /* Linux puts memset(3) in string.h */
 #include <string.h>
 #endif
