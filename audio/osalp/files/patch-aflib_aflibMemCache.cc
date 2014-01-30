--- aflib/aflibMemCache.cc.orig	2014-01-30 12:09:41.000000000 +0100
+++ aflib/aflibMemCache.cc	2014-01-30 12:10:12.000000000 +0100
@@ -24,6 +24,7 @@
 #include <config.h>
 #endif
 
+#include <cstdlib> // getenv
 
 #include "aflibMemCache.h"
 #include "aflibMemNode.h"
