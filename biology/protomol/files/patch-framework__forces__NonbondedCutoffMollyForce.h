--- framework/forces/NonbondedCutoffMollyForce.h.orig	2005-05-07 18:40:24.000000000 +0400
+++ framework/forces/NonbondedCutoffMollyForce.h	2014-08-22 20:42:42.000000000 +0400
@@ -70,7 +70,7 @@
     this->enumerator.initialize(realTopo, this->myCutoff);
 
     unsigned int n = realTopo->cellLists.size();
-    unsigned int count = numberOfBlocks(realTopo,positions);
+    unsigned int count = this->numberOfBlocks(realTopo,positions);
 
     for(unsigned int i = 0;i<count;i++){
       unsigned int l = (n*(i+1))/count - (n*i)/count;
