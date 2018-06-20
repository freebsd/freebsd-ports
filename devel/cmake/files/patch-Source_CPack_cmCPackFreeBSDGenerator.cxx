diff --git Source/CPack/cmCPackFreeBSDGenerator.cxx Source/CPack/cmCPackFreeBSDGenerator.cxx
index 91ae1a23f..a676302e7 100644
--- Source/CPack/cmCPackFreeBSDGenerator.cxx
+++ Source/CPack/cmCPackFreeBSDGenerator.cxx
@@ -339,6 +339,13 @@ int cmCPackFreeBSDGenerator::PackageFiles()
 
   std::string output_dir =
     cmSystemTools::CollapseCombinedPath(toplevel, "../");
+  if (!pkg_initialized() && pkg_init(NULL, NULL) != EPKG_OK)
+  {
+    cmCPackLogger(cmCPackLog::LOG_ERROR, 
+                  "Can not initialize libpkg." << std::endl);
+    return 0;
+  }
+
   pkg_create_from_manifest(output_dir.c_str(), ::TXZ, toplevel.c_str(),
                            manifestname.c_str(), NULL);
 
