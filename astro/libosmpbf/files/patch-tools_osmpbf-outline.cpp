--- tools/osmpbf-outline.cpp.orig	2014-03-15 15:11:32 UTC
+++ tools/osmpbf-outline.cpp
@@ -1,3 +1,6 @@
+// for isatty()
+#include <unistd.h>
+
 // used for va_list in debug-print methods
 #include <stdarg.h>
 
