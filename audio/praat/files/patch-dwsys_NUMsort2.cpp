--- dwsys/NUMsort2.cpp.orig	2022-10-10 21:25:25 UTC
+++ dwsys/NUMsort2.cpp
@@ -239,7 +239,7 @@ void VECsort3_inplace (VEC const& a, INTVEC const& iv1
 		iv2 [j] = itmp [index [j]];
 }
 
-autoINTMAT sortRows_INTMAT (constINTMAT mat, integer icol) { // TODO test me
+void sortRows_INTMAT (constINTMAT mat, integer icol) { // TODO test me
 	try {
 		Melder_require (icol > 0 && icol <= mat.ncol,
 			U"The column index is not valid.");
