--- applications/iSGProtomol-app/forces/iSGDihedralSystemForce.h.orig	2005-05-07 18:40:20.000000000 +0400
+++ applications/iSGProtomol-app/forces/iSGDihedralSystemForce.h	2014-08-22 20:49:51.000000000 +0400
@@ -71,7 +71,7 @@
       (dynamic_cast<const SemiGenericTopology<TBoundaryConditions>& >(*topo)).boundaryConditions;
 
     for (unsigned int i = 0; i < topo->dihedrals.size(); i++) 
-      calcTorsion(boundary,topo->dihedrals[i], positions, forces,
+      this->calcTorsion(boundary,topo->dihedrals[i], positions, forces,
       (*energies)[ScalarStructure::DIHEDRAL],
       (*energies)[ScalarStructure::DIHEDRAL_DELTAMU],
       energies);
@@ -95,7 +95,7 @@
 	  to = n;
 	int from = (n*i)/count;
 	for (int j = from; j < to; j++)
-	  calcTorsion(boundary, topo->dihedrals[j], positions, forces,
+	  this->calcTorsion(boundary, topo->dihedrals[j], positions, forces,
           (*energies)[ScalarStructure::DIHEDRAL],
           (*energies)[ScalarStructure::DIHEDRAL_DELTAMU],
           energies);
