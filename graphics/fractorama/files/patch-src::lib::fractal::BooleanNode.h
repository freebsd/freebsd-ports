--- lib/fractal/BooleanNode.h.orig	Sat Dec  1 01:27:59 2001
+++ lib/fractal/BooleanNode.h	Sun Dec 22 06:30:21 2002
@@ -1,7 +1,9 @@
 #ifndef _BOOLEAN_NODE_H_
 #   define _BOOLEAN_NODE_H_
 
-class ostream;
+#include <iostream>
+using namespace std;
+
 class ComplexVariables;
 class DoubleVariables;
 class ColorEnvironment;
