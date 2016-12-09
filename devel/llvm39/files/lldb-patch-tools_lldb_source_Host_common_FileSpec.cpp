--- tools/lldb/source/Host/common/FileSpec.cpp.orig	2016-12-03 16:10:10 UTC
+++ tools/lldb/source/Host/common/FileSpec.cpp
@@ -17,6 +17,7 @@
 #ifndef _MSC_VER
 #include <libgen.h>
 #endif
+#include <climits>
 #include <set>
 #include <string.h>
 #include <fstream>
