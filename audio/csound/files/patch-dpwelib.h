$FreeBSD$

--- dpwelib.h.orig	Sun Jul 14 16:03:01 2002
+++ dpwelib.h	Sun Jul 14 16:02:51 2002
@@ -56,7 +56,7 @@
 #else  /* ultrix, not NeXT */
 #ifdef clipper
 #else
-# if defined(LATTICE) || defined(WIN32) || defined(SGI)
+# if defined(LATTICE) || defined(WIN32) || defined(SGI) || defined(__FreeBSD__)
 #  include <stdlib.h>
 # else
 #  include <unistd.h>
