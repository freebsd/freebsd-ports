--- framework/forces/ImproperSystemForce.h.orig	2005-05-07 18:40:24.000000000 +0400
+++ framework/forces/ImproperSystemForce.h	2014-08-22 20:52:46.000000000 +0400
@@ -69,7 +69,7 @@
     const TBoundaryConditions &boundary = 
       (dynamic_cast<const SemiGenericTopology<TBoundaryConditions>& >(*topo)).boundaryConditions;
     for (unsigned int i = 0; i < topo->impropers.size(); i++)
-      calcTorsion(boundary,topo->impropers[i], positions, forces, (*energies)[ScalarStructure::IMPROPER],energies);
+      this->calcTorsion(boundary,topo->impropers[i], positions, forces, (*energies)[ScalarStructure::IMPROPER],energies);
   }
   template<class TBoundaryConditions> 
   inline void ImproperSystemForce<TBoundaryConditions>::parallelEvaluate(const GenericTopology* topo,
@@ -90,7 +90,7 @@
 	  to = n;
 	int from = (n*i)/count;
 	for (int j = from; j < to; j++)
-	  calcTorsion(boundary, topo->impropers[j], positions, forces, (*energies)[ScalarStructure::IMPROPER],energies);
+	  this->calcTorsion(boundary, topo->impropers[j], positions, forces, (*energies)[ScalarStructure::IMPROPER],energies);
       }
     }
   }
