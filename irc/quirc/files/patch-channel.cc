--- channel.cc.orig	Mon Jan 12 18:16:50 2004
+++ channel.cc	Tue Feb  3 23:17:24 2004
@@ -1,5 +1,6 @@
 #include <string.h>
 #include <assert.h>
+#include <sys/types.h>
 
 #ifdef DMALLOC
 #include <dmalloc.h>
