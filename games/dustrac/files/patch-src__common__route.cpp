--- ./src/common/route.cpp.orig	2014-03-29 12:42:23.000000000 +0000
+++ ./src/common/route.cpp	2014-04-14 11:24:16.431660171 +0000
@@ -18,6 +18,7 @@
 
 #include <algorithm>
 #include <cassert>
+#include <cmath>
 
 static const int CLOSING_TH = 32;
 
