--- gecode/set/int/weights.hpp.orig	2020-10-11 18:28:10 UTC
+++ gecode/set/int/weights.hpp
@@ -49,9 +49,9 @@ namespace Gecode { namespace Set { namespace Int {
     /// The value iterator
     I iter;
     /// A superset of the elements found in the iterator
-    const SharedArray<int> elements;
+    SharedArray<int> elements;
     /// Weights for all the possible elements
-    const SharedArray<int> weights;
+    SharedArray<int> weights;
     /// The current index into the elements and weights
     int index;
     /// Move to the next element
