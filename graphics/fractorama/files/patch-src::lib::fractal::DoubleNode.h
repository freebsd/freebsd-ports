--- lib/fractal/DoubleNode.h.bak	Sat Dec  1 01:27:59 2001
+++ lib/fractal/DoubleNode.h	Sun Dec 22 06:06:53 2002
@@ -1,7 +1,9 @@
 #ifndef _DOUBLE_NODE_H_
 #   define _DOUBLE_NODE_H_
 
-class ostream;
+#include <iostream>
+using namespace std;
+
 class ComplexVariables;
 class DoubleVariables;
 class ColorEnvironment;
