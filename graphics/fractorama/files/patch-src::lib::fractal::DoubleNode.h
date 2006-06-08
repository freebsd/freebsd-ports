--- lib/fractal/DoubleNode.h.orig	Fri Oct 24 22:31:52 2003
+++ lib/fractal/DoubleNode.h	Tue Mar  2 23:08:44 2004
@@ -1,7 +1,8 @@
 #ifndef _DOUBLE_NODE_H_
 #   define _DOUBLE_NODE_H_
 
-class ostream;
+#include <iostream>
+using namespace std;
 
 #define RND(x) ((x) >= 0.0 ? (int)((x) + 0.5) : (int)((x) - 0.5))
 
