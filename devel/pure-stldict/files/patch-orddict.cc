--- orddict.cc.orig	2016-01-21 06:38:47 UTC
+++ orddict.cc
@@ -1,6 +1,8 @@
 
 // This is completely analogous to hashdict.cc (which see).
 
+#include <stddef.h>
+#include <cstddef>
 #include <assert.h>
 #include <stdlib.h>
 #include <string.h>
