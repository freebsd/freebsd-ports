--- src/STEPCAFControl/STEPCAFControl_Reader.cxx.orig	2023-12-04 15:53:08 UTC
+++ src/STEPCAFControl/STEPCAFControl_Reader.cxx
@@ -1996,7 +1996,8 @@ Handle(Poly_Triangulation) createMesh(const Handle(Ste
   const Standard_Integer aNbNormals = theTriangulatedSufaceSet->NbNormals();
   // Number of pairs (Point, Normal). It is possible for one point to have multiple normals. This is
   // useful when the underlying surface is not C1 continuous.
-  const Standard_Integer aNbPairs = aNbNormals > 1 ? theTriangulatedSufaceSet->NbPnindex() : aNodes->Length();
+  // Patch from https://git.dev.opencascade.org/gitweb/?p=occt.git;a=commitdiff;h=0f6f5b64d321a988399567f6b901bef385cc8d41
+  const Standard_Integer aNbPairs = aNbNormals > 1 ? theTriangulatedSufaceSet->Pnmax() : aNodes->Length();
   const Standard_Boolean aHasNormals = aNbNormals > 0;
 
   // Counting number of triangles in the triangle strips list.
@@ -2021,7 +2022,7 @@ Handle(Poly_Triangulation) createMesh(const Handle(Ste
 
   for (Standard_Integer j = 1; j <= aNbPairs; ++j)
   {
-    const gp_XYZ& aPoint = aNodes->Value(aNbNormals > 1 ? theTriangulatedSufaceSet->PnindexValue(j) : j);
+    const gp_XYZ& aPoint = aNodes->Value((aNbNormals > 1 && theTriangulatedSufaceSet->NbPnindex() > 0) ? theTriangulatedSufaceSet->PnindexValue(j) : j);
     aMesh->SetNode(j, theFact * aPoint);
   }
 
