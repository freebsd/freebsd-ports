--- aflib/aflibConfig.h.orig	2007-01-16 19:26:39 UTC
+++ aflib/aflibConfig.h
@@ -31,6 +31,9 @@
 // Note that g++ does not really need this. If -O with compile func in .h will be inline
 #define INLINE inline
 
+#include <cstdlib>
+#include <cstring>
+
 #include "aflib.h"
 
 
