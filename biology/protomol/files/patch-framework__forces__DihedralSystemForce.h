--- framework/forces/DihedralSystemForce.h.orig	2005-05-07 18:40:24.000000000 +0400
+++ framework/forces/DihedralSystemForce.h	2014-08-22 20:41:24.000000000 +0400
@@ -72,7 +72,7 @@
     const TBoundaryConditions &boundary = 
       (dynamic_cast<const SemiGenericTopology<TBoundaryConditions>& >(*topo)).boundaryConditions;
     for (unsigned int i = 0; i < topo->dihedrals.size(); i++) 
-      calcTorsion(boundary,topo->dihedrals[i], positions, forces,(*energies)[ScalarStructure::DIHEDRAL],energies);
+      this->calcTorsion(boundary,topo->dihedrals[i], positions, forces,(*energies)[ScalarStructure::DIHEDRAL],energies);
   }
   template<class TBoundaryConditions> 
   inline void DihedralSystemForce<TBoundaryConditions>::parallelEvaluate(const GenericTopology* topo,
@@ -93,7 +93,7 @@
 	  to = n;
 	int from = (n*i)/count;
 	for (int j = from; j < to; j++)
-	  calcTorsion(boundary, topo->dihedrals[j], positions, forces, (*energies)[ScalarStructure::DIHEDRAL],energies);
+	  this->calcTorsion(boundary, topo->dihedrals[j], positions, forces, (*energies)[ScalarStructure::DIHEDRAL],energies);
       }
     }
   }
