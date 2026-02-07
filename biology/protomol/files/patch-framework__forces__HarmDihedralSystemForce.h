--- framework/forces/HarmDihedralSystemForce.h.orig	2005-05-07 18:40:24.000000000 +0400
+++ framework/forces/HarmDihedralSystemForce.h	2014-08-22 20:42:13.000000000 +0400
@@ -119,7 +119,7 @@
       {
 	if (static_cast<int>(i) != myDihedral) {
 	  if(computeOthers) {
-	    calcTorsion(boundary,topo->dihedrals[i], positions, forces,(*energies)[ScalarStructure::DIHEDRAL],energies);
+	    this->calcTorsion(boundary,topo->dihedrals[i], positions, forces,(*energies)[ScalarStructure::DIHEDRAL],energies);
 	  }
 	}
 	else {
@@ -149,7 +149,7 @@
 	int from = (n*i)/count;
 	for (int j = from; j < to; j++){
 	  if (j != myDihedral) {
-	    calcTorsion(boundary,topo->dihedrals[j], positions, forces,(*energies)[ScalarStructure::DIHEDRAL],energies);
+	    this->calcTorsion(boundary,topo->dihedrals[j], positions, forces,(*energies)[ScalarStructure::DIHEDRAL],energies);
 	  }
 	  else {
 	    harmCalcTorsion(topo,boundary,topo->dihedrals[j], positions, forces,(*energies)[ScalarStructure::DIHEDRAL],energies);
