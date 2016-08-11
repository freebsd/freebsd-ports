--- src/base/file_handle.cpp.orig	2015-11-06 13:40:13 UTC
+++ src/base/file_handle.cpp
@@ -26,6 +26,8 @@
 #define O_TEXT    0
 #endif
 
+#include <sys/stat.h>
+
 using namespace std;
 
 namespace base {
