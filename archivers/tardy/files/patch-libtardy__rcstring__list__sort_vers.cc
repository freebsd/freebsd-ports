--- ./libtardy/rcstring/list/sort_vers.cc.orig	2011-10-03 14:12:58.000000000 +0200
+++ ./libtardy/rcstring/list/sort_vers.cc	2011-10-04 10:09:13.000000000 +0200
@@ -21,6 +21,8 @@
 
 #include <libtardy/rcstring/list.h>
 
+#include "strverscmp.h"
+
 
 static int
 cmp(const void *va, const void *vb)
