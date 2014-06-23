--- ./ofxconnect/ofxpartner.cpp.orig	2013-04-16 15:50:51.000000000 -0400
+++ ./ofxconnect/ofxpartner.cpp	2014-06-22 19:44:48.000000000 -0400
@@ -37,6 +37,7 @@
 #include <vector>
 #include <algorithm>
 #include <string.h>
+#include <unistd.h>
 
 using std::string;
 using std::vector;
