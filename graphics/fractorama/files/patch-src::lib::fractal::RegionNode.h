--- lib/fractal/RegionNode.h.orig	Fri Oct 24 22:33:47 2003
+++ lib/fractal/RegionNode.h	Tue Mar  2 23:10:41 2004
@@ -1,8 +1,10 @@
 #ifndef _REGION_NODE_H_
 #   define _REGION_NODE_H_
 
+#include <iostream>
+using namespace std;
+
 class ComplexNode;
-class ostream;
 
 class RegionNode
 {
