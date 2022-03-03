--- src/Mod/Part/Gui/ViewProviderExt.cpp.orig	2022-03-02 17:15:16.283319000 +0100
+++ src/Mod/Part/Gui/ViewProviderExt.cpp	2022-03-02 23:49:04.036080000 +0100
@@ -137,26 +137,17 @@
                                      const Handle(Poly_Triangulation)& aPolyTri,
                                      TColgp_Array1OfDir& theNormals)
 {
-    const TColgp_Array1OfPnt& aNodes = aPolyTri->Nodes();
-
     if(aPolyTri->HasNormals())
     {
         // normals pre-computed in triangulation structure
-        const TShort_Array1OfShortReal& aNormals = aPolyTri->Normals();
-        const Standard_ShortReal*       aNormArr = &(aNormals.Value(aNormals.Lower()));
-
-        for(Standard_Integer aNodeIter = aNodes.Lower(); aNodeIter <= aNodes.Upper(); ++aNodeIter)
+        for(Standard_Integer aNodeIter = 1; aNodeIter <= aPolyTri->NbNodes(); ++aNodeIter)
         {
-            const Standard_Integer anId = 3 * (aNodeIter - aNodes.Lower());
-            const gp_Dir aNorm(aNormArr[anId + 0],
-                               aNormArr[anId + 1],
-                               aNormArr[anId + 2]);
-            theNormals(aNodeIter) = aNorm;
+            theNormals(aNodeIter) = aPolyTri->Normal(aNodeIter);
         }
 
         if(theFace.Orientation() == TopAbs_REVERSED)
         {
-            for(Standard_Integer aNodeIter = aNodes.Lower(); aNodeIter <= aNodes.Upper(); ++aNodeIter)
+            for(Standard_Integer aNodeIter = 1; aNodeIter <= aPolyTri->NbNodes(); ++aNodeIter)
             {
                 theNormals.ChangeValue(aNodeIter).Reverse();
             }
@@ -172,16 +163,13 @@
     const Standard_Real    aTol      = Precision::Confusion();
     Handle(TShort_HArray1OfShortReal) aNormals = new TShort_HArray1OfShortReal(1, aPolyTri->NbNodes() * 3);
     const Poly_Array1OfTriangle& aTriangles = aPolyTri->Triangles();
-    const TColgp_Array1OfPnt2d*  aNodesUV   = aPolyTri->HasUVNodes() && !aSurf.IsNull()
-            ? &aPolyTri->UVNodes()
-            : NULL;
+    const Standard_Boolean hasUV = aPolyTri->HasUVNodes() && !aSurf.IsNull();
     Standard_Integer aTri[3];
 
-    for(Standard_Integer aNodeIter = aNodes.Lower(); aNodeIter <= aNodes.Upper(); ++aNodeIter)
+    for(Standard_Integer aNodeIter = 1; aNodeIter <= aPolyTri->NbNodes(); ++aNodeIter)
     {
         // try to retrieve normal from real surface first, when UV coordinates are available
-        if(aNodesUV == NULL
-                || GeomLib::NormEstim(aSurf, aNodesUV->Value(aNodeIter), aTol, theNormals(aNodeIter)) > 1)
+        if(hasUV || GeomLib::NormEstim(aSurf, aPolyTri->UVNode(aNodeIter), aTol, theNormals(aNodeIter)) > 1)
         {
             // compute flat normals
             gp_XYZ eqPlan(0.0, 0.0, 0.0);
@@ -189,8 +177,8 @@
             for(thePolyConnect.Initialize(aNodeIter); thePolyConnect.More(); thePolyConnect.Next())
             {
                 aTriangles(thePolyConnect.Value()).Get(aTri[0], aTri[1], aTri[2]);
-                const gp_XYZ v1(aNodes(aTri[1]).Coord() - aNodes(aTri[0]).Coord());
-                const gp_XYZ v2(aNodes(aTri[2]).Coord() - aNodes(aTri[1]).Coord());
+                const gp_XYZ v1(aPolyTri->Node(aTri[1]).Coord() - aPolyTri->Node(aTri[0]).Coord());
+                const gp_XYZ v2(aPolyTri->Node(aTri[2]).Coord() - aPolyTri->Node(aTri[1]).Coord());
                 const gp_XYZ vv = v1 ^ v2;
                 const Standard_Real aMod = vv.Modulus();
 
@@ -204,7 +192,7 @@
             theNormals(aNodeIter) = (aModMax > aTol) ? gp_Dir(eqPlan) : gp::DZ();
         }
 
-        const Standard_Integer anId = (aNodeIter - aNodes.Lower()) * 3;
+        const Standard_Integer anId = (aNodeIter - 1) * 3;
         aNormals->SetValue(anId + 1, (Standard_ShortReal)theNormals(aNodeIter).X());
         aNormals->SetValue(anId + 2, (Standard_ShortReal)theNormals(aNodeIter).Y());
         aNormals->SetValue(anId + 3, (Standard_ShortReal)theNormals(aNodeIter).Z());
@@ -214,7 +202,7 @@
 
     if(theFace.Orientation() == TopAbs_REVERSED)
     {
-        for(Standard_Integer aNodeIter = aNodes.Lower(); aNodeIter <= aNodes.Upper(); ++aNodeIter)
+        for(Standard_Integer aNodeIter = 1; aNodeIter <= aPolyTri->NbNodes(); ++aNodeIter)
         {
             theNormals.ChangeValue(aNodeIter).Reverse();
         }
