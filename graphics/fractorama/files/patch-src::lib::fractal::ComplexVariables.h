--- lib/fractal/ComplexVariables.h.bak	Sat Dec  1 01:27:59 2001
+++ lib/fractal/ComplexVariables.h	Sun Dec 22 06:06:53 2002
@@ -3,7 +3,9 @@
 
 #include "dcomplex.h"
 
-class ostream;
+#include <iostream>
+using namespace std;
+
 struct ComplexEntry;
 
 class ComplexVariables
