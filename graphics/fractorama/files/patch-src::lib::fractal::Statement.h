--- lib/fractal/Statement.h.orig	Sat Dec  1 01:27:59 2001
+++ lib/fractal/Statement.h	Sun Dec 22 07:03:48 2002
@@ -1,13 +1,16 @@
 #ifndef _STATEMENT_H_
 #   define _STATEMENT_H_
 
+#include "tf.h"
+
+#include <iostream>
+using namespace std;
+
 class ComplexVariables;
 class DoubleVariables;
 class ColorEnvironment;
 class InfiniteLoopCallback;
-class ostream;
 
-#include "tf.h"
 
 struct LoopControl
 {
