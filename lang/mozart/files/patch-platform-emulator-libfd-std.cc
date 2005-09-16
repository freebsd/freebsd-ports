--- ./platform/emulator/libfd/std.cc.orig	Fri Sep  5 05:28:25 2003
+++ ./platform/emulator/libfd/std.cc	Sat Sep  3 18:46:08 2005
@@ -44,7 +44,9 @@
 
 #else
 
-#include <values.h>
+#include <limits.h>
+#include <float.h>
+#define DMAXPOWTWO DBL_MAX_EXP
 
 #endif
 
