--- ngsolve/comp/postproc.cpp.orig
+++ ngsolve/comp/postproc.cpp
@@ -9,6 +9,7 @@
 */
 
 #include <comp.hpp>
+#include <fem.hpp>
 
 namespace ngcomp
 {
@@ -274,8 +275,8 @@
 	if (dimflux > 1)
 	  {
 	    FlatMatrix<SCAL> elmat(dnumsflux.Size(), lh);
-	    dynamic_cast<const BlockBilinearFormIntegrator&> (fluxbli)
-	      . Block() . AssembleElementMatrix (felflux, eltrans, elmat, lh);
+	    BlockBilinearFormIntegrator const& fluxbli_ref = dynamic_cast<const BlockBilinearFormIntegrator&> (fluxbli);
+	    fluxbli_ref . Block() . AssembleElementMatrix (felflux, eltrans, elmat, lh);
 	    CholeskyFactors<SCAL> invelmat(elmat);
 
 	    FlatVector<SCAL> hv1(dnumsflux.Size(), lh);
