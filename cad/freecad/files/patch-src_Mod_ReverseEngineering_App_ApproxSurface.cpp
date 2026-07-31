--- src/Mod/ReverseEngineering/App/ApproxSurface.cpp.orig	2026-07-02 14:13:51 UTC
+++ src/Mod/ReverseEngineering/App/ApproxSurface.cpp
@@ -63,7 +63,7 @@ SplineBasisfunction::SplineBasisfunction(
 
     if (vKnots.Length() != vMults.Length() || iSize != sum) {
         // Throw exception
-        Standard_ConstructionError::Raise("BSplineBasis");
+        throw Standard_ConstructionError("BSplineBasis");
     }
 
     int k = 0;
@@ -89,7 +89,7 @@ void SplineBasisfunction::SetKnots(TColStd_Array1OfRea
 void SplineBasisfunction::SetKnots(TColStd_Array1OfReal& vKnots, int iOrder)
 {
     if (_vKnotVector.Length() != vKnots.Length()) {
-        Standard_RangeError::Raise("BSplineBasis");
+        throw Standard_RangeError("BSplineBasis");
     }
 
     _vKnotVector = vKnots;
@@ -105,7 +105,7 @@ void SplineBasisfunction::SetKnots(TColStd_Array1OfRea
 
     if (vKnots.Length() != vMults.Length() || _vKnotVector.Length() != sum) {
         // Throw exception
-        Standard_RangeError::Raise("BSplineBasis");
+        throw Standard_RangeError("BSplineBasis");
     }
     int k = 0;
     for (int i = vMults.Lower(); i <= vMults.Upper(); i++) {
@@ -166,7 +166,7 @@ void BSplineBasis::AllBasisFunctions(double fParam, TC
 void BSplineBasis::AllBasisFunctions(double fParam, TColStd_Array1OfReal& vFuncVals)
 {
     if (vFuncVals.Length() != _iOrder) {
-        Standard_RangeError::Raise("BSplineBasis");
+        throw Standard_RangeError("BSplineBasis");
     }
 
     int iIndex = FindSpan(fParam);
@@ -268,7 +268,7 @@ void BSplineBasis::DerivativesOfBasisFunction(
 {
     int iMax = iMaxDer;
     if (Derivat.Length() != iMax + 1) {
-        Standard_RangeError::Raise("BSplineBasis");
+        throw Standard_RangeError("BSplineBasis");
     }
     // kth derivatives (k> degrees) are zero
     if (iMax >= _iOrder) {
@@ -649,10 +649,10 @@ ParameterCorrection::ParameterCorrection(
     , _usUCtrlpoints(usUCtrlpoints)
     , _usVCtrlpoints(usVCtrlpoints)
     , _vCtrlPntsOfSurf(0, usUCtrlpoints - 1, 0, usVCtrlpoints - 1)
-    , _vUKnots(0, usUCtrlpoints - usUOrder + 1)
-    , _vVKnots(0, usVCtrlpoints - usVOrder + 1)
-    , _vUMults(0, usUCtrlpoints - usUOrder + 1)
-    , _vVMults(0, usVCtrlpoints - usVOrder + 1)
+    , _vUKnots(0, (int)(usUCtrlpoints - usUOrder + 1))
+    , _vVKnots(0, (int)(usVCtrlpoints - usVOrder + 1))
+    , _vUMults(0, (int)(usUCtrlpoints - usUOrder + 1))
+    , _vVMults(0, (int)(usVCtrlpoints - usVOrder + 1))
 {
     _bGetUVDir = false;
     _bSmoothing = false;
