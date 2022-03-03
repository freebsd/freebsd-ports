--- src/3rdParty/salomesmesh/src/SMESH/SMESH_Mesh.cpp.orig	2022-01-30 21:22:20.383703000 +0100
+++ src/3rdParty/salomesmesh/src/SMESH/SMESH_Mesh.cpp	2022-01-30 21:22:56.240456000 +0100
@@ -64,7 +64,6 @@
 
 #include <GEOMUtils.hxx>
 
-#undef _Precision_HeaderFile
 #include <BRepBndLib.hxx>
 #include <BRepPrimAPI_MakeBox.hxx>
 #include <Bnd_Box.hxx>
