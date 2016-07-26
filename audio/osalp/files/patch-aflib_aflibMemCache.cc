--- aflib/aflibMemCache.cc.orig	2007-01-16 19:26:39 UTC
+++ aflib/aflibMemCache.cc
@@ -24,6 +24,7 @@
 #include <config.h>
 #endif
 
+#include <cstdlib> // getenv
 
 #include "aflibMemCache.h"
 #include "aflibMemNode.h"
