--- lib/fractal/ComplexNode.h.bak	Sat Dec  1 01:27:59 2001
+++ lib/fractal/ComplexNode.h	Sun Dec 22 06:06:53 2002
@@ -3,7 +3,9 @@
 
 #include "dcomplex.h"
 
-class ostream;
+#include <iostream>
+using namespace std;
+
 class ComplexVariables;
 class DoubleVariables;
 class ColorEnvironment;
