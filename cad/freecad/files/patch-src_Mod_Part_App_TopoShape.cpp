--- src/Mod/Part/App/TopoShape.cpp.orig	2020-11-14 19:57:17 UTC
+++ src/Mod/Part/App/TopoShape.cpp
@@ -584,17 +584,21 @@ void TopoShape::importIges(const char *FileName)
         if (aReader.ReadFile(encodeFilename(FileName).c_str()) != IFSelect_RetDone)
             throw Base::FileException("Error in reading IGES");
 
+#if OCC_VERSION_HEX < 0x070500
         Handle(Message_ProgressIndicator) pi = new ProgressIndicator(100);
         pi->NewScope(100, "Reading IGES file...");
         pi->Show();
         aReader.WS()->MapReader()->SetProgress(pi);
+#endif
 
         // make brep
         aReader.ClearShapes();
         aReader.TransferRoots();
         // one shape that contains all subshapes
         this->_Shape = aReader.OneShape();
+#if OCC_VERSION_HEX < 0x070500
         pi->EndScope();
+#endif
     }
     catch (Standard_Failure& e) {
         throw Base::CADKernelError(e.GetMessageString());
@@ -608,16 +612,20 @@ void TopoShape::importStep(const char *FileName)
         if (aReader.ReadFile(encodeFilename(FileName).c_str()) != IFSelect_RetDone)
             throw Base::FileException("Error in reading STEP");
 
+#if OCC_VERSION_HEX < 0x070500
         Handle(Message_ProgressIndicator) pi = new ProgressIndicator(100);
         aReader.WS()->MapReader()->SetProgress(pi);
         pi->NewScope(100, "Reading STEP file...");
         pi->Show();
+#endif
 
         // Root transfers
         aReader.TransferRoots();
         // one shape that contains all subshapes
         this->_Shape = aReader.OneShape();
+#if OCC_VERSION_HEX < 0x070500
         pi->EndScope();
+#endif
     }
     catch (Standard_Failure& e) {
         throw Base::CADKernelError(e.GetMessageString());
@@ -630,7 +638,7 @@ void TopoShape::importBrep(const char *FileName)
         // read brep-file
         BRep_Builder aBuilder;
         TopoDS_Shape aShape;
-#if OCC_VERSION_HEX >= 0x060300
+#if OCC_VERSION_HEX >= 0x060300 && OCC_VERSION_HEX < 0x070500
         Handle(Message_ProgressIndicator) pi = new ProgressIndicator(100);
         pi->NewScope(100, "Reading BREP file...");
         pi->Show();
@@ -652,7 +660,7 @@ void TopoShape::importBrep(std::istream& str, int indi
         // read brep-file
         BRep_Builder aBuilder;
         TopoDS_Shape aShape;
-#if OCC_VERSION_HEX >= 0x060300
+#if OCC_VERSION_HEX >= 0x060300 && OCC_VERSION_HEX < 0x070500
         if (indicator) {
             Handle(Message_ProgressIndicator) pi = new ProgressIndicator(100);
             pi->NewScope(100, "Reading BREP file...");
@@ -750,10 +758,12 @@ void TopoShape::exportStep(const char *filename) const
 
         const Handle(XSControl_TransferWriter)& hTransferWriter = aWriter.WS()->TransferWriter();
         Handle(Transfer_FinderProcess) hFinder = hTransferWriter->FinderProcess();
+#if OCC_VERSION_HEX < 0x070500
         Handle(Message_ProgressIndicator) pi = new ProgressIndicator(100);
         hFinder->SetProgress(pi);
         pi->NewScope(100, "Writing STEP file...");
         pi->Show();
+#endif
 
         if (aWriter.Transfer(this->_Shape, STEPControl_AsIs) != IFSelect_RetDone)
             throw Base::FileException("Error in transferring STEP");
@@ -767,7 +777,9 @@ void TopoShape::exportStep(const char *filename) const
 
         if (aWriter.Write(encodeFilename(filename).c_str()) != IFSelect_RetDone)
             throw Base::FileException("Writing of STEP failed");
+#if OCC_VERSION_HEX < 0x070500
         pi->EndScope();
+#endif
     }
     catch (Standard_Failure& e) {
         throw Base::CADKernelError(e.GetMessageString());
