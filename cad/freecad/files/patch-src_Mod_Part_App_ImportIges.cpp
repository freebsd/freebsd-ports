--- src/Mod/Part/App/ImportIges.cpp.orig	2020-11-14 19:52:35 UTC
+++ src/Mod/Part/App/ImportIges.cpp
@@ -90,16 +90,20 @@ int Part::ImportIgesParts(App::Document *pcDoc, const 
 
 #if 1
         std::string aName = fi.fileNamePure();
+#if OCC_VERSION_HEX < 0x070500
         Handle(Message_ProgressIndicator) pi = new ProgressIndicator(100);
         pi->NewScope(100, "Reading IGES file...");
         pi->Show();
         aReader.WS()->MapReader()->SetProgress(pi);
+#endif
 
         // make model
         aReader.ClearShapes();
         //Standard_Integer nbRootsForTransfer = aReader.NbRootsForTransfer();
         aReader.TransferRoots();
+#if OCC_VERSION_HEX < 0x070500
         pi->EndScope();
+#endif
 
         // put all other free-flying shapes into a single compound
         Standard_Boolean emptyComp = Standard_True;
