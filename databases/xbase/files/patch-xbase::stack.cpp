--- xbase/stack.cpp.orig	Fri Nov 10 20:04:17 2000
+++ xbase/stack.cpp	Sat Nov 22 21:57:49 2003
@@ -59,7 +59,8 @@
 
 #include <string.h>
 #include <stdlib.h>
-#include <iostream.h>
+#include <iostream>
+using std::cout;
 
 #include <xbase/xstack.h>
 
