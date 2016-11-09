--- src/lib_json/json_reader.cpp.orig	2016-10-30 21:28:16 UTC
+++ src/lib_json/json_reader.cpp
@@ -3,6 +3,11 @@
 // recognized in your jurisdiction.
 // See file LICENSE for detail or copy at http://jsoncpp.sourceforge.net/LICENSE
 
+// fix for lang/gcc5+
+#if __GNUC__ == 5
+#include <cstdio>
+#endif
+
 #if !defined(JSON_IS_AMALGAMATION)
 #include <json/assertions.h>
 #include <json/reader.h>
