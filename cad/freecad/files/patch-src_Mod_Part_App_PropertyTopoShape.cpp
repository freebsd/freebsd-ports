--- src/Mod/Part/App/PropertyTopoShape.cpp.orig	2019-10-04 10:26:07 UTC
+++ src/Mod/Part/App/PropertyTopoShape.cpp
@@ -281,9 +281,9 @@ static void BRepTools_Write(const TopoDS_Shape& Sh, St
 static Standard_Boolean  BRepTools_Write(const TopoDS_Shape& Sh, 
                                    const Standard_CString File)
 {
-  ofstream os;
+  std::ofstream os;
 #if OCC_VERSION_HEX >= 0x060800
-  OSD_OpenStream(os, File, ios::out);
+  OSD_OpenStream(os, File, std::ios::out);
 #else
   os.open(File, ios::out);
 #endif
