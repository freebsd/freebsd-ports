--- tcltk.cc.orig	Mon Jan 12 18:25:11 2004
+++ tcltk.cc	Tue Feb  3 23:18:41 2004
@@ -1,6 +1,7 @@
 #include <stdlib.h>
 #include <stdarg.h>
 #include <string.h>
+#include <sys/types.h>
 
 #ifdef DMALLOC
 #include <dmalloc.h>
