--- lib/fractal/ComplexVariables.h.orig	Fri Oct 24 22:41:22 2003
+++ lib/fractal/ComplexVariables.h	Tue Mar  2 23:07:05 2004
@@ -3,7 +3,9 @@
 
 #include "dcomplex.h"
 
-class ostream;
+#include <iostream>
+using namespace std;
+
 class ComplexEntry;
 
 class ComplexVariables
