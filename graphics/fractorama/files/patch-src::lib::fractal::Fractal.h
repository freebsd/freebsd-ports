--- lib/fractal/Fractal.h.bak	Fri Jan 25 01:22:39 2002
+++ lib/fractal/Fractal.h	Sun Dec 22 06:06:53 2002
@@ -3,7 +3,9 @@
 
 // Forward Declarations
 
-class ostream;
+#include <iostream>
+using namespace std;
+
 class BooleanNode;
 class Statement;
 class InfiniteLoopCallback;
