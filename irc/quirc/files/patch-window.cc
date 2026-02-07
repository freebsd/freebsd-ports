--- window.cc.orig	Sat May 15 14:20:48 1999
+++ window.cc	Tue Feb  3 23:20:36 2004
@@ -1,3 +1,5 @@
+#include <sys/types.h>
+
 #ifdef DMALLOC
 #include <dmalloc.h>
 #endif
