--- xbase/ndx.cpp.orig	Wed Mar 21 01:28:53 2001
+++ xbase/ndx.cpp	Sat Nov 22 21:56:03 2003
@@ -66,7 +66,8 @@
 #endif
 
 #include <xbase/xbase.h>
-#include <iostream.h>
+#include <iostream>
+using std::cout;
 
 #ifdef XB_INDEX_NDX
 
