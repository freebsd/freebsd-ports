--- qmls/mccluskey.cpp.orig	Wed Dec 11 21:46:22 2002
+++ qmls/mccluskey.cpp	Wed Dec 11 21:47:15 2002
@@ -200,7 +200,7 @@
     value = primeImplicants[implicants[i]]->ValueAt(0);
     diffBits = primeImplicants[implicants[i]]->GetDiffBits(numDiffBits);
 
-    mask = (unum)pow(2,numBits-1);
+    mask = (unum)pow(2.0,(int)numBits-1);
     for (int j=(int)numBits-1; j>=0; j--)
     {
       bool dBit=false;
