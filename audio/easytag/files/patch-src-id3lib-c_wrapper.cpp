--- src/id3lib/c_wrapper.cpp.orig	2014-04-13 16:14:15.000000000 +0400
+++ src/id3lib/c_wrapper.cpp	2014-04-13 16:14:33.000000000 +0400
@@ -32,6 +32,8 @@
 #include <id3/field.h>
 #include <id3/tag.h>
 
+#include "id3_bugfix.h"
+
 #ifdef __cplusplus
 extern "C"
 {
