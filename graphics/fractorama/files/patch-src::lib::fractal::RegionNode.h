--- lib/fractal/RegionNode.h.orig	Sat Dec  1 01:27:59 2001
+++ lib/fractal/RegionNode.h	Sun Dec 22 07:02:08 2002
@@ -1,11 +1,13 @@
 #ifndef _REGION_NODE_H_
 #   define _REGION_NODE_H_
 
+#include <iostream>
+using namespace std;
+
 class ComplexNode;
 class ComplexVariables;
 class DoubleVariables;
 class ColorEnvironment;
-class ostream;
 
 class RegionNode
 {
