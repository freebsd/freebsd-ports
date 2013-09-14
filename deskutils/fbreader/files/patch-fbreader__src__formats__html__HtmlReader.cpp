--- ./fbreader/src/formats/html/HtmlReader.cpp.orig	2010-04-02 00:14:24.000000000 +1100
+++ ./fbreader/src/formats/html/HtmlReader.cpp	2013-09-12 00:31:39.434367202 +1100
@@ -19,6 +19,7 @@
 
 #include <algorithm>
 #include <cctype>
+#include <cstdlib>
 
 #include <ZLInputStream.h>
 #include <ZLXMLReader.h>
