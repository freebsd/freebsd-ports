--- lib/fractal/Statement.h.orig	Fri Oct 24 22:34:04 2003
+++ lib/fractal/Statement.h	Tue Mar  2 23:12:00 2004
@@ -1,10 +1,12 @@
 #ifndef _STATEMENT_H_
 #   define _STATEMENT_H_
 
-class InfiniteLoopCallback;
-class ostream;
-
 #include "tf.h"
+
+#include <iostream>
+using namespace std;
+
+class InfiniteLoopCallback;
 
 struct LoopControl
 {
