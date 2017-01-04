--- ./aws-cpp-sdk-core/source/external/json-cpp/jsoncpp.cpp.orig	2017-01-03 09:13:57.776272000 +0000
+++ ./aws-cpp-sdk-core/source/external/json-cpp/jsoncpp.cpp	2017-01-03 09:14:40.064338000 +0000
@@ -83,7 +83,7 @@
 
 
 #include <aws/core/external/json-cpp/json.h>
-
+#include <cmath>
 
 // //////////////////////////////////////////////////////////////////////
 // Beginning of content of file: src/lib_json/json_tool.h
