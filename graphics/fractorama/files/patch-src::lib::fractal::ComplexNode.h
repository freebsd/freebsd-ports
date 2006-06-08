--- lib/fractal/ComplexNode.h.orig	Fri Oct 24 22:31:06 2003
+++ lib/fractal/ComplexNode.h	Tue Mar  2 23:05:13 2004
@@ -3,7 +3,8 @@
 
 #include "dcomplex.h"
 
-class ostream;
+#include <iostream>
+using namespace std;
 
 class ComplexNode
 {
