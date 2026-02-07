--- qmls/quinegroup.cpp.orig	Wed Dec 11 21:42:49 2002
+++ qmls/quinegroup.cpp	Wed Dec 11 21:44:24 2002
@@ -111,7 +111,7 @@
   unsigned int headData = head->GetData();
   for (i=0; i<numDiffBits; i++)
   {
-    unsigned int numToSkip = (unsigned int)pow(2,i);
+    unsigned int numToSkip = (unsigned int)pow(2.0,(int)i);
     diffBits[i] = ValueAt(numToSkip) - headData;
   }
 
