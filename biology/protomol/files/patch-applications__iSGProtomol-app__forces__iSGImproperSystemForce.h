--- applications/iSGProtomol-app/forces/iSGImproperSystemForce.h.orig	2005-05-07 18:40:20.000000000 +0400
+++ applications/iSGProtomol-app/forces/iSGImproperSystemForce.h	2014-08-22 20:50:15.000000000 +0400
@@ -67,7 +67,7 @@
     const TBoundaryConditions &boundary = 
       (dynamic_cast<const SemiGenericTopology<TBoundaryConditions>& >(*topo)).boundaryConditions;
     for (unsigned int i = 0; i < topo->impropers.size(); i++)
-      calcTorsion(boundary,topo->impropers[i], positions, forces,
+      this->calcTorsion(boundary,topo->impropers[i], positions, forces,
       (*energies)[ScalarStructure::IMPROPER],
       (*energies)[ScalarStructure::IMPROPER_DELTAMU],
       energies);
@@ -91,7 +91,7 @@
 	  to = n;
 	int from = (n*i)/count;
 	for (int j = from; j < to; j++)
-	  calcTorsion(boundary, topo->impropers[j], positions, forces,
+	  this->calcTorsion(boundary, topo->impropers[j], positions, forces,
           (*energies)[ScalarStructure::IMPROPER],
           (*energies)[ScalarStructure::IMPROPER_DELTAMU],
           energies);
