--- src/Mod/Part/App/ImportStep.cpp.orig	2020-11-14 19:53:50 UTC
+++ src/Mod/Part/App/ImportStep.cpp
@@ -105,10 +105,12 @@ int Part::ImportStepParts(App::Document *pcDoc, const 
         throw Base::FileException("Cannot open STEP file");
     }
 
+#if OCC_VERSION_HEX < 0x070500
     Handle(Message_ProgressIndicator) pi = new ProgressIndicator(100);
     aReader.WS()->MapReader()->SetProgress(pi);
     pi->NewScope(100, "Reading STEP file...");
     pi->Show();
+#endif
 
     // Root transfers
     Standard_Integer nbr = aReader.NbRootsForTransfer();
@@ -117,7 +119,9 @@ int Part::ImportStepParts(App::Document *pcDoc, const 
         Base::Console().Log("STEP: Transferring Root %d\n",n);
         aReader.TransferRoot(n);
     }
+#if OCC_VERSION_HEX < 0x070500
     pi->EndScope();
+#endif
 
     // Collecting resulting entities
     Standard_Integer nbs = aReader.NbShapes();
