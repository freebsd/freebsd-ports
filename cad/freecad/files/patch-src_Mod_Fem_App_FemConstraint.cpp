--- src/Mod/Fem/App/FemConstraint.cpp.orig	2022-02-04 00:04:15.767125000 +0100
+++ src/Mod/Fem/App/FemConstraint.cpp	2022-02-04 00:04:38.270409000 +0100
@@ -36,8 +36,6 @@
 # include <BRepAdaptor_Curve.hxx>
 # include <GCPnts_AbscissaPoint.hxx>
 # include <Adaptor3d_IsoCurve.hxx>
-# include <Adaptor3d_HSurface.hxx>
-# include <BRepAdaptor_HSurface.hxx>
 # include <BRepAdaptor_Surface.hxx>
 # include <GProp_GProps.hxx>
 # include <BRepGProp.hxx>
@@ -248,8 +246,8 @@
             gp_Pnt center;
 
             // Get an estimate for the number of arrows by finding the average length of curves
-            Handle(Adaptor3d_HSurface) hsurf;
-            hsurf = new BRepAdaptor_HSurface(surface);
+            Handle(Adaptor3d_Surface) hsurf;
+            hsurf = new BRepAdaptor_Surface(surface);
 
             Adaptor3d_IsoCurve isoc(hsurf);
             try {
