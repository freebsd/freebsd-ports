--- tools/lldb/source/Host/common/FileSpec.cpp.orig	2017-04-03 04:25:09 UTC
+++ tools/lldb/source/Host/common/FileSpec.cpp
@@ -17,6 +17,7 @@
 #include <libgen.h>
 #endif
 #include <fstream>
+#include <limits.h>
 #include <set>
 #include <string.h>
 
