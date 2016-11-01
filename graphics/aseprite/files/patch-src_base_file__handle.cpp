--- src/base/file_handle.cpp.orig	2016-09-23 15:59:20 UTC
+++ src/base/file_handle.cpp
@@ -27,6 +27,8 @@
 #define O_TEXT    0
 #endif
 
+#include <sys/stat.h>
+
 using namespace std;
 
 namespace base {
