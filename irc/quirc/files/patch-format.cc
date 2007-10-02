--- format.cc.orig	2004-01-12 17:32:01.000000000 +0800
+++ format.cc	2007-10-02 22:46:34.000000000 +0800
@@ -1,4 +1,5 @@
 #include <stdarg.h>
+#include <sys/types.h>
 
 #include "quirc.h"
 #include "hash.h"
@@ -405,5 +406,5 @@
 }
 
 int fexists(const char *type) {
-  return (int)hash_get(&formats,type);
+  return (int)*hash_get(&formats,type);
 }
