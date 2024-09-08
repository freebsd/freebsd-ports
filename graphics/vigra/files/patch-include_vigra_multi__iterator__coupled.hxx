--- include/vigra/multi_iterator_coupled.hxx.orig	2018-10-19 16:12:20 UTC
+++ include/vigra/multi_iterator_coupled.hxx
@@ -490,7 +490,7 @@ class CoupledScanOrderIterator<N, HANDLES, 0>
     CoupledScanOrderIterator operator--(int)
     {
         CoupledScanOrderIterator res(*this);
-        --this;
+        --*this;
         return res;
     }
 
