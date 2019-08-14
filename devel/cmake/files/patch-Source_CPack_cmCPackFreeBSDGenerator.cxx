--- Source/CPack/cmCPackFreeBSDGenerator.cxx.orig	2019-06-04 16:37:41 UTC
+++ Source/CPack/cmCPackFreeBSDGenerator.cxx
@@ -331,6 +331,13 @@ int cmCPackFreeBSDGenerator::PackageFiles()
 
   std::string broken_suffix = std::string("-") +
     var_lookup("CPACK_TOPLEVEL_TAG") + std::string(GetOutputExtension());
+  if (!pkg_initialized() && pkg_init(NULL, NULL) != EPKG_OK)
+  {
+    cmCPackLogger(cmCPackLog::LOG_ERROR, 
+                  "Can not initialize libpkg." << std::endl);
+    return 0;
+  }
+
   for (std::string& name : packageFileNames) {
     cmCPackLogger(cmCPackLog::LOG_DEBUG, "Packagefile " << name << std::endl);
     if (has_suffix(name, broken_suffix)) {
