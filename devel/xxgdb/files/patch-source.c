--- source.c.orig	1995-04-21 16:16:02 UTC
+++ source.c
@@ -74,7 +74,7 @@
  *    LoadFile():	Search for a file and open it for display.
  */
 
-#ifndef NeXT
+#if !defined(NeXT) && !defined(__FreeBSD__) && !defined(__DragonFly__)
 #include <malloc.h>
 #endif
 #include <stdlib.h>
