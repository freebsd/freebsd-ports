--- hash.cc.orig	Mon Jan 12 17:53:35 2004
+++ hash.cc	Tue Feb  3 23:19:58 2004
@@ -1,5 +1,6 @@
 #include <stdlib.h>
 #include <string.h>
+#include <sys/types.h>
 
 #ifdef DMALLOC
 #include <dmalloc.h>
