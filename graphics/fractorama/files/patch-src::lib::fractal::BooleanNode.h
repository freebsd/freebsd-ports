--- lib/fractal/BooleanNode.h.orig	Fri Oct 24 22:30:40 2003
+++ lib/fractal/BooleanNode.h	Tue Mar  2 23:03:24 2004
@@ -1,7 +1,8 @@
 #ifndef _BOOLEAN_NODE_H_
 #   define _BOOLEAN_NODE_H_
 
-class ostream;
+#include <iostream>
+using namespace std;
 
 class BooleanNode
 {
