--- src/tree.cpp.orig	Sat Feb 22 23:13:45 2003
+++ src/tree.cpp	Sat Feb 22 23:13:52 2003
@@ -2,11 +2,12 @@
 * tree.cpp
 */
 
+#include <qstack.h>
+
 #include "tree.h"
 #include "move.h"
 #include "qgo.h"
 #include <iostream.h>
-#include <qstack.h>
 
 Tree::Tree(int board_size)
 {
