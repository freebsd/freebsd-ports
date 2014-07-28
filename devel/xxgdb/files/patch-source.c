--- source.c.orig	Sat Apr 22 01:16:02 1995
+++ source.c	Fri Nov 17 21:38:58 2000
@@ -74,7 +74,7 @@
  *    LoadFile():	Search for a file and open it for display.
  */
 
-#ifndef NeXT
+#if !defined(NeXT) && !defined(__FreeBSD__)
 #include <malloc.h>
 #endif
 #include <stdlib.h>
