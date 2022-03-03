--- src/Mod/Part/App/Tools.cpp.orig	2022-02-03 20:59:16.862252000 +0100
+++ src/Mod/Part/App/Tools.cpp	2022-02-03 21:43:13.008464000 +0100
@@ -25,10 +25,9 @@
 # include <cassert>
 # include <gp_Pln.hxx>
 # include <gp_Lin.hxx>
-# include <Adaptor3d_HCurveOnSurface.hxx>
 # include <Geom_BSplineSurface.hxx>
 # include <Geom_Plane.hxx>
-# include <GeomAdaptor_HCurve.hxx>
+# include <GeomAdaptor_Curve.hxx>
 # include <GeomAPI_IntSS.hxx>
 # include <Geom_Line.hxx>
 # include <Geom_Point.hxx>
@@ -98,8 +97,8 @@
     return found;
 }
 
-/*! The objects in \a theBoundaries must be of the type Adaptor3d_HCurveOnSurface or
-GeomAdaptor_HCurve or Geom_Point indicating type of a constraint. Otherwise an exception
+/*! The objects in \a theBoundaries must be of the type Adaptor3d_CurveOnSurface or
+GeomAdaptor_Curve or Geom_Point indicating type of a constraint. Otherwise an exception
 Standard_TypeMismatch is thrown.
 
 If the \a theBoundaries list is empty then Standard_ConstructionError is thrown.
@@ -138,15 +137,15 @@
                 assert (0);
                 Standard_ConstructionError::Raise ("Tools::makeSurface()");
             }
-            else if (aCur->IsKind (STANDARD_TYPE (Adaptor3d_HCurveOnSurface))) {
+            else if (aCur->IsKind (STANDARD_TYPE (Adaptor3d_CurveOnSurface))) {
                 //G1 constraint
-                Handle(Adaptor3d_HCurveOnSurface) aHCOS (Handle(Adaptor3d_HCurveOnSurface)::DownCast (aCur));
+                Handle(Adaptor3d_CurveOnSurface) aHCOS (Handle(Adaptor3d_CurveOnSurface)::DownCast (aCur));
                 Handle (GeomPlate_CurveConstraint) aConst = new GeomPlate_CurveConstraint (aHCOS, 1 /*GeomAbs_G1*/,aNbPnts, aTol3d, anAngTol, aCurvTol);
                 aPlateBuilder.Add (aConst);
             }
-            else if (aCur->IsKind (STANDARD_TYPE (GeomAdaptor_HCurve))) {
+            else if (aCur->IsKind (STANDARD_TYPE (GeomAdaptor_Curve))) {
                 //G0 constraint
-                Handle(GeomAdaptor_HCurve) aHC (Handle(GeomAdaptor_HCurve)::DownCast (aCur));
+                Handle(GeomAdaptor_Curve) aHC (Handle(GeomAdaptor_Curve)::DownCast (aCur));
                 Handle (GeomPlate_CurveConstraint) aConst = new GeomPlate_CurveConstraint (aHC, 0 /*GeomAbs_G0*/, aNbPnts, aTol3d);
                 aPlateBuilder.Add (aConst);
             }
