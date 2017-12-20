--- compiler/generator/tools.cpp.orig	2017-06-07 15:07:18 UTC
+++ compiler/generator/tools.cpp
@@ -23,6 +23,8 @@
 // Date: October 29, 2010
 // Returns the cache line size (in bytes) of the processor, or 0 on failure
 
+#include <sys/types.h>
+
 #if defined(__APPLE__)
 
 #include <sys/sysctl.h>
