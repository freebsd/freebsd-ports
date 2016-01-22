--- hashdict.cc.orig	2016-01-21 06:37:40 UTC
+++ hashdict.cc
@@ -1,6 +1,8 @@
 
 // This uses unordered_map, so a recent C++ library is required for now.
 
+#include <stddef.h>
+#include <cstddef>
 #include <assert.h>
 #include <stdlib.h>
 #include <string.h>
